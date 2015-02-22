import java.util.*;
import java.io.*;
class App {
	public static void main(String[] args) {
		InputStreamReader isr = new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader (isr);
		String data;
		Encryption en;
		System.out.println("Escribe la frase a cifrar");
		try{
			data=br.readLine ();
		}catch (IOException e){
			data="";
		}
		en = new Encryption(data);
		System.out.println(en.toString());
	}
	
}
/*
*Class Encryption
*Clase que aplica la tecnica de monocifrado a un String dado
*/
class Encryption{
	/*
	*public static final String ALPHABET[], arreglo de clase, conjunto de letras mayúsculas que se usarán para el cifrado
	*private String[] key, conjunto de letras permutadas para cifrar y descifrar la información
	*String info, información a cifrar
	*String info, información cifrada
	*/
	public static final String ALPHABET[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	private String[] key = new String[ALPHABET.length];
	String info;
	String infoEncrypt="";
	/*
	*Constructor
	*Recibe:
	*String info, cadena de texto a encriptar.
	*/
	Encryption(String info){
		buildKey();
		this.info=info;
		encrypt();
	}
	/*
	*void buildKey()
	*Método que genera una llave de cifrado mediante la permutación de un conjunto de letras original ALPHABET, se ayuda de Collections.shuffle()
	*/	
	void buildKey(){
		List<String> temp=Arrays.asList(ALPHABET.clone());
		Collections.shuffle(temp);
		temp.toArray(key);
	}
	/*
	*void encrypt()
	*Método que cifra el contenido del String info, asignando las letras de la llave relacionadas con el alfabeto original.
	*Si info contiene espacios, se eliminan.
	*Si info contiene caracteres fuera de ALPHABET se ignoran y se pierden en el cifrado
	*El String info se maneja en mayúsculas y de esa forma se sustituyen los nuevos carácteres.
	*/
	void encrypt(){
		String infoNoSpaces=info.toUpperCase().replace(" ","");
		for(int i=0; i<infoNoSpaces.length();i++)
			try{
				infoEncrypt+=key[Arrays.asList(ALPHABET).indexOf(String.valueOf(infoNoSpaces.charAt(i)))];}
			catch (ArrayIndexOutOfBoundsException e){}
	}
	/*
	*public String toString()
	*Método que genera una representación en cadena de texto del objeto Encryption.
	*Devuelve:
	*String str, representación String del objeto.
	*/
	public String toString(){
		String str="";
		str+="Abecedario:\n"+Arrays.toString(ALPHABET).replace(",","");
		str+="\nLlave:\n"+Arrays.toString(key).replace(",","");
		str+="\nOriginal:\n"+info;
		str+="\nCifrada:\n"+infoEncrypt;
		return str;
	}
}