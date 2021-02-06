X = int(input("X: "))
x1 = X // 100
x2 = X % 100 // 10
x3 = X % 10
Y = x2*100 + x3*10 +x1
print(Y)
