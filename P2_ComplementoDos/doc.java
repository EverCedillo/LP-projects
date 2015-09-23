/*****************
* Cedillo Martínez Jesús Everardo
* García González Brenda
* 11 Feb 2014
******************/
import java.util.Vector;
import java.io.*;

/*
*Clase principal donde se ejecutan los métodos de la clase Binary
* @author: Cedillo Martínez Jesús Everardo
* @author: García González Brenda
* @version: 11/02/2014
*/
public class App {
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