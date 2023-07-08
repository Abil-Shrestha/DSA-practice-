def calculate(self, string: str) -> int:
      
           # number?
           # +ve or -ve
           # open paraen
           # close paren

           stack = []
           sum = 0
           sign = 1
           length = len(string)
           index = 0

           while index < length:
               character = string[index]

               if character.isdigit():
                  
                   current_num = 0
                   while index < length and string[index].isdigit():
                       current_num = 10 * current_num + int(string[index])
                       index += 1
                       sum = sum + current_num * sign
                       index -= 1
               elif character == '-':
                   sign = -1
               elif character == '+':
                   sign = 1
               elif character == '(':
                   stack.append(sum)
                   stack.append(sign)
                   sum, sign = 0, 1
               elif character == ')':
                   current_sign = stack.pop() # handle sign
                   sum = sum * current_sign
                   sum = sum + stack.pop()

               index += 1
           return sum
