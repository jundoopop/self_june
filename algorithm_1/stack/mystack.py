class stack:
     def __init__(self):
          self.array = []
          self.num = 0

     def push(self, num):
          self.array.append(num)
     
     def pop(self):
          if len(self.array) != 0:
               return self.array.pop() 
          else:
               return -1

     def size(self):
          return len(self.array)

     def empty(self):
          if len(self.array) == 0:
               return 1
          else:
               return 0

     def top(self):
          if len(self.array) == 0:
               return -1
          else:
               return self.array[-1]

if __name__ == '__main__':
     s_test = stack()
     tester = int(input())

     for i in range(0,tester):
          order = input()

          if order == 'push':
               order = int(order.replace('push ', ''))
               s_test.push(order)

          elif order == 'top' :
               print(s_test.top())
               
          elif order == 'pop' :
               print(s_test.pop())
          
          elif order == 'empty' :
               print(s_test.empty())

          elif order == 'top' :
               print(s_test.top())
          
   
          