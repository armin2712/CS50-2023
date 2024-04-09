import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)
    #print(new_cases)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    cases={}
    previous_cases={}
    for row in reader:
        state=row['state']
        cas=row['cases']
        if state in cases:
            sum_cases=sum(int(i) for i in previous_cases[state])
            cases[state].append(int(cas) - sum_cases)
            previous_cases[state].append(int(cas) - sum_cases)
            if len(cases[state]) > 14:
                del cases[state][0]
        else:
            cases[state]=[cas]
            previous_cases[state]=[cas]
    return cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
        for state in states:
            last=(sum(new_cases[state][7:]))/7
            first=(sum(new_cases[state][:7]))/7
            try:
                avg=(last-first)/last
            except ZeroDivisionError:
                avg=100
            n='increase' if last > first else 'decrease'
            print(f"{state} had a 7-day average of {last} and a {n} of {avg}%.")








main()
