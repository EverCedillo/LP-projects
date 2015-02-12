/*****************
* Cedillo Martínez Jesús Everardo
* García González Brenda
* 11 Feb 2014
******************/
import java.util.Vector;
import java.io.*;

/*
class App
Clase principal donde se ejecutan los métodos de la clase Binary
*/
class App {
	public static void main(String[] args) {
		InputStreamReader isr = new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader (isr);
		int n;
		System.out.println("Escribe el número en base 10 para obtener su complemento a dos:");

		try{
			n=Integer.parseInt(br.readLine ());
		}catch (IOException e){
			n=0;
		}
		Binary bin = new Binary(n);
		System.out.println("El numero "+n+" en binario es: \n"+bin.toString()+"\ny su complemento a dos es:\n"+bin.twosComplement().toString());
	}
}
/*
Class Binary
clase que genera y almacena los digitos de la representación binaria de un número entero de base 10
*/
class Binary {
	/*
	int num, número en base 10
	Vector<Boolean> binary, colección booleana que representa los digitos del número en binario
	donde los valores true corresponden a 1 y los false a 0, y cuyos indices corresponden al 
	valor según un sistema posicional.
	*/
	int num;
	Vector<Boolean> binary = new Vector<Boolean>();
	/*
	Binary(int num)
	Constructor
	Recibe:
	int num, numero entero en base 10
	*/
	Binary(int num){
		this.num=num;
		buildBinary();
	}
	/*
	void buildBinary()
	Realiza la contrucción de la colección booleana, realizando corrimientos para poder operar cada
	bit del número y almacenar su valor, además añade el bit de signo.
	*/
	void buildBinary(){
		for(int i=0;i<Math.floor(Math.log(Math.abs(num))/Math.log(2))+1;i++)
			binary.add(((num>>>i)&1)==1);
		binary.add(num<0);
	}
	/*
	Binary twosComplement()
	Realiza el complemento a dos de la representación binaria de num, se axulia del operador de NOT
	Devuelve:
	Binary (com+1), objeto Binary, complemento a dos de this
	*/
	Binary twosComplement(){
		int com=~num;
		return new Binary(com+1);
	}
	/*
	public String toString()
	Gnera la representación en cadena de texto del objeto Binary usado
	Devuelve:
	String str, represntación String de Binary
	*/
	public String toString(){
		String str="";
		for(int i=binary.size()-1;i>=0;i--)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}

}