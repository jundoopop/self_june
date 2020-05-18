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
          order = input().split()
          call = order[0]

          if call == 'push':
               s_test.push(order[1])

          elif call == 'top' :
               print(s_test.top())
               
          elif call == 'pop' :
               print(s_test.pop())
          
          elif call == 'empty' :
               print(s_test.empty())

          elif call == 'size' :
               print(s_test.size())
          
   
          


