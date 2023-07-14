class MyQueue:

    def __init__(self):
        self.one=[]
        self.two=[]

    def push(self, x: int) -> None:
        self.one.append(x)

    def pop(self) -> int:
        self.peek()
        return self.two.pop()

    def peek(self) -> int:
        if not self.two:
            while self.one:
                self.two.append(self.one.pop())
        return self.two[-1]

    def empty(self) -> bool:
        return not self.one and not self.two

