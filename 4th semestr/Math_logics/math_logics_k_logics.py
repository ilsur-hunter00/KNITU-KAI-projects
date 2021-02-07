first_priorit = {'*': (1, lambda x, y, k: multipl_(x,y,k) )}
second_priorit = {'i': (2, lambda x, k: haract_(x,k))} 

def haract_(x,k):
    while (True):
        if x == 1:
            res = k - 1
            return res

        else:
            res = 0
            return res

def multipl_(x,y,k):
    result = (int(x) * int(y)) % k
    return result

def checkN(getn):
    while (True):
        if getn == 1 or getn == 2 :
            break
        else:
            print("Введите либо 1, либо 2: ")
            getn = int(input())
    return getn

def checkK(getk):
    while True:
        if (getk>= 2):
            break
        else:
            print("Введите число от 2-ух: ")
            getk = int(input())
    return getk

def correct(formula, rx=1, ry=1):
    def parse(formula_string): 
        number = ''
        for s in formula_string:
            if s in '123456789':
                number += s
            elif number:
                yield ((int(number))%getk)
                number = ''
            if s in first_priorit or s in second_priorit or s in "()" or s in 'X,Y':
                yield s
        if number:
            yield ((int(number))%getk)

    def shunt(parsed_formula):
        myStack = []
        for token in parsed_formula:
            if token in first_priorit:
                while myStack and myStack[-1] != "(" and first_priorit[token][0] <= first_priorit[myStack[-1]][0]:
                    yield myStack.pop()
                myStack.append(token)
            elif token == ")":
                while myStack:
                    x = myStack.pop()
                    if x == "(":
                        break
                    yield x
            elif token == "(":
                myStack.append(token)
            else:
                yield token
        while myStack:
            yield myStack.pop()

    def calc(pol, rx=1, ry=1):
        myStack = []
        for token in pol:
            if token == 'X':
                myStack.append(int(rx))
            elif token == 'Y':
                myStack.append ( int ( ry ) )
            elif token in second_priorit:
                x = myStack.pop()
                myStack.append(second_priorit[token][1](x, getk))
            elif token in first_priorit:
                y, x = myStack.pop(), myStack.pop()
                myStack.append(first_priorit[token][1](x, y, getk))
            else:
                myStack.append(token)
        return myStack[0]

    return calc(shunt(parse(formula)), rx, ry) 

def precorrect(formula_string):
    number = ''
    formula_result = ""
    formula_string.replace ( ' ' , '' )
    for s in formula_string:
        if s in '1234567890':
           number += s
        if number:  
            formula_result += str((int ( number )))
            number = ''
        if s in first_priorit or s in second_priorit or s in "()" or s in 'X,Y':
            formula_result += s
    return formula_result

firstForm = ""
firstForm_ = ""
secondForm = ""

print("Здравствуйте! Студент группы 4211 Вафин И.М. (вариант №5).")

while int(1):
    menu= int(input("1-Ввод данных в консоль.\n2-Ввод данных с файла.\nВыйти - любая кнопка." ))
    if menu == 1:
        getk = int(input("Введите k: "))
        getk = checkK(getk)
        getn = int(input("Введите n (1 или 2): "))
        getn = checkN(getn)
        f = open("console-file.txt", "a")
        print("Условные обозначения:\n'X,Y' - переменные\n'*' - умножение по mod k\nXi - характ. ф-ия I_s(X)")
        formula = str(input("Введите функцию: \n "))
        mnE=[int(i) for i in input("Введите значение множества Е (< k) через пробел : ").split()]
        classT = True
        if getn == 1 :
            print("  X  "  +precorrect(formula) + "\n")
            f.write("  X  " + precorrect(formula) + "\n")
            for i in range(getk):
                func = correct(formula, i)
                if i in mnE and not (func in mnE):
                    classT = False
                print("  " + str(i) + "  " + str(func))
                f.write("  " + str(i) + "  " + str(func) + "\n")
                if func != 0:
                    if func != (getk - 1):
                        firstForm = firstForm + str(func) + "&" + "I_" + str(i) + "(X)" + " V "
                    else:
                        firstForm = firstForm + "I_" + str(i) + "(X)" + " V "
                    secondForm = secondForm + str(func) + "*" + "j_" + str(i) + "(X)" + " + "
                if func == (getk - 1):
                    firstForm_ += str(getk - 1) + "&"
                elif func != 0:
                    firstForm_ = firstForm_ + "(" + str(func) + " V " + "I_" + str(i) + "(X)" + ")&"
                else:
                    firstForm_ = firstForm_ + "I_" + str(i) + "(X)" + "&"
        if getn == 2:
            print("  X  " + "  Y  " + precorrect(formula) + "\n")
            f.write("  X  " + "  Y  " + precorrect(formula) + "\n")
            for i in range(getk):
                for j in range(getk):
                    func = correct(formula, i, j)
                    if i in mnE and j in mnE and not (func in mnE):
                        classT = False
                    print("  " + str(i) + "  " + str(j) + "  " + str(func))
                    f.write("  " + str(i) + "  " + str(j) + "  " + str(func) + "\n")
                    if func != 0:
                        if func != (getk - 1):
                            firstForm = firstForm + str(func) + "&" + "I_" + str(i) + "(X)" + "&" + "I_" + str(j) + "(Y)" + " V "
                        else:
                            firstForm = firstForm + "I_" + str(i) + "(X)" + "&" + "I_" + str(j) + "(Y)" + " V "
                        secondForm = secondForm + str(func) + "*" + "j_" + str(i) + "(X)" + "*" + "j_" + str(j) + "(Y)" + " + "
                    if func == (getk - 1):
                        firstForm_ += str(getk - 1) + "&"
                    elif func != 0:
                        firstForm_ = firstForm_ + "(" + str(func) + " V " + "I_" + str(i) + "(X)" + " V " + "I_" + str(j) + "(Y)" + ")&"
                    else:
                        firstForm_ = firstForm_ + "(I_" + str(i) + "(X)"  + "I_" + str(j) + "(Y)" + ")&"
        firstForm = firstForm[0:-3]
        firstForm_ = firstForm_[0:-1]
        secondForm = secondForm[0:-3]
        print("1 форма (аналог СДНФ):\n" + firstForm + "\n")
        print("1 форма аналог СКНФ:\n" + firstForm_ + "\n")
        print("2 форма:\n" + secondForm + "\n")
        print("Функция принадлежит множеству E? - ", str(classT) + "\n")
        f.write("1 форма (аналог СДНФ):\n" + firstForm + "\n")
        f.write("1 форма аналог СКНФ:\n" + firstForm_ + "\n")
        f.write("2 форма:\n" + secondForm + "\n")
        f.write("Функция принадлежит множеству E? - " + str(classT) + "\n")
        f.write("______________________________\n")
        f.close()
        firstForm_ = ""
        firstForm = ""
        secondForm = ""
    if menu == 2:
        f1 =open('input.txt',"r")
        x = f1.readlines()
        getk=int(x[0])
        getn=int(x[1])
        f = open("output.txt", "a")
        formula = x[2]
        mnE = [int(i) for i in x[3].split()]
        classT = True
        if getn == 1:
            print("  X  " + precorrect(formula) + "\n")
            f.write("  X  " + precorrect(formula) + "\n")
            for i in range(getk):
                func = correct(formula, i)
                if i in mnE and not (func in mnE):
                    classT = False
                print("  " + str(i) + "  " + str(func) + "\n")
                f.write("  " + str(i) + "  " + str(func) + "\n")
                if func != 0:
                    if func != (getk - 1):
                        firstForm = firstForm + str(func) + "&" + "I_" + str(i) + "(X)" + " V "
                    else:
                        firstForm = firstForm + "I_" + str(i) + "(X)" + " V "
                    secondForm = secondForm + str(func) + "*" + "j_" + str(i) + "(X)" + " + "
                if func == (getk - 1):
                    firstForm_ += str(getk - 1) + "&"
                elif func != 0:
                    firstForm_ = firstForm_ + "(" + str(func) + " V " + "I_" + str(i) + "(X)" + ")&"
                else:
                    firstForm_ = firstForm_ + "I_" + str(i) + "(X)" + "&"
        if getn == 2:
            print("  X  " + "Y  " + precorrect(formula) + "\n")
            f.write("  X  " + "Y  " + precorrect(formula) + "\n")
            for i in range(getk):
                for j in range(getk):
                    func = correct(formula, i, j)
                    if i in mnE and j in mnE and not (func in mnE):
                        classT = False
                    print("  " + str(i) + "  " + str(j) + "  " + str(func))
                    f.write("  " + str(i) + "  " + str(j) + "  " + str(func) + "\n")
                    if func != 0:
                        if func != (getk - 1):
                            firstForm = firstForm + str(func) + "&" + "I_" + str(i) + "(X)" + "&" + "I_" + str(
                                j) + "(Y)" + " V "
                        else:
                            firstForm = firstForm + "I_" + str(i) + "(X)" + "&" + "I_" + str(j) + "(Y)" + " V "
                        secondForm = secondForm + str(func) + "*" + "j_" + str(i) + "(X)" + "*" + "j_" + str(
                            j) + "(Y)" + " + "
                    if func == (getk - 1):
                        firstForm_ += str(getk - 1) + "&"
                    elif func != 0:
                        firstForm_ = firstForm_ + "(" + str(func) + " V " + "I_" + str(
                            i) + "(X)" + " V " + "I_" + str(j) + "(Y)" + ")&"
                    else:
                        firstForm_ = firstForm_ + "(I_" + str(i) + "(X)" + "I_" + str(j) + "(Y)" + ")&"
        firstForm = firstForm[0:-3]
        firstForm_ = firstForm_[0:-1]
        secondForm = secondForm[0:-3]
        print("1 форма (аналог СДНФ):\n" + firstForm + "\n")
        print("1 форма аналог СКНФ:\n" + firstForm_ + "\n")
        print("2 форма:\n" + secondForm + "\n")
        print("Функция принадлежит множеству E? - ", str(classT) + "\n")
        f.write("1 форма (аналог СДНФ):\n" + firstForm + "\n")
        f.write("1 форма аналог СКНФ:\n" + firstForm_ + "\n")
        f.write("2 форма:\n" + secondForm + "\n")
        f.write("Функция принадлежит множеству E? - " + str(classT) + "\n")
        f.write("______________________________\n")
        f.close()
        f1.close()
        firstForm_ = ""
        firstForm = ""
        secondForm = ""
    else: break
