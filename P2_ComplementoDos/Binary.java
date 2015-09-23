import java.util.Vector;
/**
*clase que genera y almacena los digitos de la representación binaria de un número entero de base 10
* @author: Cedillo Martínez Jesús Everardo
* @author: García González Brenda
* @version: 11/02/2014
*/
public class Binary {
	/**
	*int num, número en base 10
	*Vector<Boolean> binary, colección booleana que representa los digitos del número en binario donde los valores true corresponden a 1 y los false a 0, y cuyos indices corresponden al valor según un sistema posicional.
	*/
	int num;
	Vector<Boolean> binary = new Vector<Boolean>();
	/**
	*Constructor
	*@param num numero entero en base 10
	*/
	public Binary(int num){
		this.num=num;
		buildBinary();
	}
	/**
	*Realiza la contrucción de la colección booleana, realizando corrimientos para poder operar cada	bit del número y almacenar su valor, además añade el bit de signo.	La cantidad de bits para representación del número binario está sujeta a la cantidad de bits	necesarios, por ejemplo -128 se representa en 
	*/
	public void buildBinary(){
		for(int i=0;i<Math.floor(Math.log(Math.abs(num))/Math.log(2))+1;i++)
			binary.add(((num>>>i)&1)==1);
		binary.add(num<0);
	}
	/**
	*Realiza el complemento a dos de la representación binaria de num, se axulia del operador de NOT
	*@see buildBinary()
	*@return objeto Binary, complemento a dos de this
	*/
	public Binary twosComplement(){
		int com=~num;
		return new Binary(com+1);
	}
	/**
	*Gnera la representación en cadena de texto del objeto Binary usado
	*@return str, represntación String de Binary
	*/
	public String toString(){
		String str="";
		for(int i=binary.size()-1;i>=0;i--)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}

}