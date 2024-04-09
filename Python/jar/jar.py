class Jar:
    def __init__(self, capacity=12):
        if capacity < 1:
            raise ValueError('Jar capacity must be an positiv integer!')
        self._capacity=capacity
        self.cookies=0

    def __str__(self):
            return  "🍪" * self.cookies

    def deposit(self, n):

        if self.cookies+n > self._capacity:
            raise ValueError("Too many cookies, cant fit in jar!")
        else:
            self.cookies+=n

    def withdraw(self, n):
        if(n > self.cookies):
            raise ValueError("There are not that many cookies in the Jar!")
        else:
            self.cookies-=n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self.cookies



jar=Jar(10)
jar.deposit(9)

print(jar)

