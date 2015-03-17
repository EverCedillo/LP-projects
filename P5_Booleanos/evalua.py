def evalua(expresion):
  data = expresion.split()
  #Las expresiones deben estar separadas por espacios en blanco
  dicOp = {'+':'+', '-':'-','*':'*','/':'/','^':'**','res':'%','y':'and','v':'or','n':'not','<=':'<=','>=':'>=','==':'==','!=':'!='}
  dicOpU = {}
  ops = []
  val = []
  for i in data:
    if i == '(':
      pass #ignorar
    elif i in dicOp:
      ops.append(dicOp[i])
    elif i == ')':
      op = ops.pop()
      n2 = val.pop()
      n1 = val.pop()
      #print str(n1) + op + str(n2)
      va = eval(str(n1)+ " "+op+ " "+str(n2))
      val.append(va)
    else:
      val.append(float(i))
  if ops != []:
    raise Exception('Error,La pila de operadores no esta vacia,faltan parentesis de cierre')
  return val.pop()

