import math
def evalua(expresion):
  data = expresion.split()
  dicOp = {'+':'+', '-':'-','*':'*','/':'/','^':'**','res':'%','and':'and','or':'or','<=':'<=','>=':'>=','==':'==','!=':'!=','<':'<','>':'>'}
  dicOpU = {'sqrt':'sqrt','sin':'sin','cos':'cos','atan':'atan','tan':'tan','acos':'acos'}
  dicOpN ={'not':'not'}
  ops = []
  val = []
  for i in data:
    if i == '(':
      pass
    elif i in dicOp:
      ops.append(dicOp[i])
    elif i in dicOpU:
      ops.append(dicOpU[i])
    elif i in dicOpN:
      ops.append(dicOpN[i])
    elif i == ')':
      op = ops.pop()
      if op in dicOp:
        n2 = val.pop()
        n1 = val.pop()
	print str(n1)+ op + str(n2)
        va = eval(str(n1)+ " "+ op + " "+str(n2))
      if op in dicOpN:
          n1 = val.pop()
          va = eval(op+"("+str(n1)+")")
      if op in dicOpU:
          n1 = val.pop()
          va = eval("math."+op+"("+str(n1)+")")
      val.append(va)
    else:
      val.append(float(i))
  if ops != []:
    raise Exception('Error,La pila de operadores no esta vacia,faltan parentesis de cierre')
  return val.pop()

