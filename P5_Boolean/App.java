/*
Para cada caracter leído
        Si es separador
                Si es de apertura
                        ignorar 
        Si es de cierre
                sacar operador de la pila
                si es aritmético
                        Si el operador es unario
                                sacar operando booleano y operar
                                guardar resultado en pila de operandos aritméticos
                        Si es binario
                                sacar dos operandos booleanos de la pila
                                operar en el orden requerido
                                guardar resultado en la pila de operandos aritméticos
                si es de comparación
                        sacar dos operandos aritméticos de la pila
                        operar en el orden requerido
                        guardar resultado en la pila de operandos booleanos
                si es booleano
                        Si el operador es unario
                                sacar operando booleano y operar
                                guardar resultado en pila de operandos booleanos
                        Si es binario
                                sacar dos operandos booleanos de la pila 
                                operar en el orden requerido
                                guardar resultado en la pila de operandos booleanos
        Si es operando
                Si es booleano
                        Meter en pila de operando booleano
                Si es aritmético
                        meter en la pila de operandos aritméticos
        Si es operador
                meter en pila de operadores


*/

        //(((((4+5)<2)v((3+4)>(2)))+4)>(10))
import java.util.Stack;              
class App{
	public static void main(String[] args) {
		
	}
}


class Infix{
	public static char OPENING_CHAR = '(';
	public static char CLOSURE_CHAR = ')';
	public static String[] bOperand = {"OR","NOT","AND"};
	String info;
	Infix(String toEval){
		info=toEval;
	}
	void eval(){
		Stack<String> bOperand;
		Stack<String> aOperand;
		Stack<String> operator = new Stack<String>();
		for(int i=0;i<info.length();i++){
			if(info.charAt(i)==')'){
				operator.pop();
			}

		}
	}

}