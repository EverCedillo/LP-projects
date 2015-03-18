import math
def evalua(expresion):
  data = expresion.split()
  #Las expresiones deben estar separadas por espacios en blanco
  dicOp = {'+':'+', '-':'-','*':'*','/':'/','^':'**','res':'%','y':'and','o':'or','<=':'<=','>=':'>=','==':'==','!=':'!=','<':'<','>':'>'}
  dicOpU = {'sqrt':'sqrt','sin':'sin','cos':'cos','atan':'atan','tan':'tan','acos':'acos','n':'not'}
  ops = []
  val = []
  for i in data:
    if i == '(':
      pass #ignorar
    elif i in dicOp:
      ops.append(dicOp[i])
    elif i in dicOpU:
      ops.append(dicOpU[i])
    elif i == ')':
      op = ops.pop()
      if op in dicOp:
        n2 = val.pop()
        n1 = val.pop()
        va = eval(str(n1)+ " "+op+ " "+str(n2))
      elif op in dicOpU:
        n1 = val.pop()
        if op == "not":
          print "holi"
          va = eval(op+"("+str(n1)+")")
        else:
          va = eval("math."+op+"("+str(n1)+")")
      #print str(n1) + op + str(n2)
      
      val.append(va)
    #elif i in dicOpU:
    #  ops.append
    else:
      val.append(float(i))
  if ops != []:
    raise Exception('Error,La pila de operadores no esta vacia,faltan parentesis de cierre')
  return val.pop()

