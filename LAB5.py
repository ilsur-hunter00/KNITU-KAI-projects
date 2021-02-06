X = int(input("X:"))
x1 = X // 100
x2 = X % 100 // 10
x3 = X % 10
S1 = x1 + x2 + x3
S2 = x1 * x2 * x3
print(S1, S2)
