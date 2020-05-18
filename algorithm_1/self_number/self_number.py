def self_number(num):
     numbers = set(range(1, num+1))
     construct = set()

     for n in range(1, num+1):
          for j in str(n):
               n += int(j)
          construct.add(n)

     s_numbers = numbers - construct

     for i in sorted(s_numbers):
          print(i)

if __name__ == "__main__":
     self_number(10000)