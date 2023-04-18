productions = {1: 'S->AA',
               2: 'A->aA',
               3: 'A->b'}
dict1 = {0: ['a3', 'b4', 'A2', 'S1'],
         1: ['$*'],
         2: ['a3', 'b4', 'A5'],
         3: ['a3', 'b4', 'A6'],
         4: ['aR3', 'bR3', '$R3'],
         5: ['aR1', 'bR1', '$R1'],
         6: ['aR2', 'bR2', '$R2']}

# -------
# Grammar - 2
# productions = {
#                1:'E->E+T',
#                2:'E->T',
#                3:'T->T*F',
#                4:'T->F',
#                5:'F->i'}
# dict1 = {0: ['i4', 'E1', 'T2', 'F3'],
#          1: ['$%','+5'],
#          2: ['+R2', '*6', '$R2'],
#          3: ['+R4', '*R4', '$R4'],
#          4: ['+R5', '*R5', '$5'],
#          5: ['i4', 'T7', 'F3'],
#          6: ['i4', 'F8'],
#          7: ['+R1','*6','$R1'],
#          8: ['+R3','*R3','$R3']}
string = 'aabb$'
ptr = 0
state = 0
stack = '0'
str_stack = 'aabb$'
print('Stack'.ljust(10), 'String'.ljust(10), 'Action'.ljust(10))
print(stack.ljust(10), str_stack.ljust(10), 'Start'.ljust(10))
break_var = 1
red = 0
while break_var:
    ch = string[ptr]  # You read the actual string first for the left most symbol
    t = [item[0] for item in dict1[state]]
    if ch in t:  # To check if the symbol exists or not for a given state
        temp = ''.join([ele for ele in dict1[state] if ele[0] == ch])  # temp is like a3 or b4
        if temp[1] == '*':
            print("String accepted")
            break
        if not 65 <= ord(ch) <= 90 and temp[1] != 'R':  # For terminals
            stack += temp
            state = int(temp[1])
            act = 'Go to ' + str(state)
            ptr += 1
            print(stack.ljust(10), str_stack.ljust(10), act.ljust(10))
        elif not 65 <= ord(ch) <= 90 and temp[1] == 'R':
            prod_no = temp[2]
            str_stack = str_stack[:ptr - 1 - red] + str_stack[ptr - red:]
            prod = productions[int(prod_no)]
            head, body = prod.split('->')
            len_body = len(body)
            pop_len = 2 * len_body
            stack = stack[:len(stack) - pop_len]
            stack += str(head)
            act = 'Reduce to ' + prod
            print(stack.ljust(10), str_stack.ljust(10), act.ljust(10))
            new_state, sym = stack[-2:], stack[-2:]
            new_state = int(new_state[0])
            sym = sym[-1]
            te = ''.join([ele for ele in dict1[new_state] if ele[0] == sym])
            state = int(te[1])
            stack += str(state)
            act = "Go to " + str(state)
            red += 1
            print(stack.ljust(10), str_stack.ljust(10), act.ljust(10))
    else:
        break