import java.util.*;
import java.io.*;
class App {
	public static void main(String[] args) {
		InputStreamReader isr = new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader (isr);
		float data;
		FloatBinary fb,fb2;
		System.out.println("Escribe el numero");
		try{
			data=Float.parseFloat(br.readLine ());
		}catch (IOException e){
			data=0;
		}
		fb = new FloatBinary(data);
		fb2 = new FloatBinary("01000001100111100010000000000000");
		System.out.println(fb.toString());
		System.out.println(fb2.toString());
	}
}
/*
*Class FloatBinary
*Clase que obtiene la representación en bits, de un número tipo float
*/
class FloatBinary {
	/*
	*float num, número flotante a obtener su representación
	*List<Boolean> binary, lista de booleanos que representan los bits del número flotante donde los valores True representan 1 y los False 0
	*/
	float num;
	List<Boolean> binary;
	/*
	*Constructor
	*Recibe:
	*float num, numero a representar en bits
	*/
	FloatBinary(float num){
		binary = new ArrayList<Boolean>();
		this.num=num;
		buildBinary();
	}
	FloatBinary(String bin){
		binary =new ArrayList<Boolean>();
		buildList(bin);
		buildFloat();
	}
	/*
	*void buildBinary()
	*Método que construye la representación en bits de num, divido en tres partes, exponente, parte entera y parte fraccionaria.
	*El exponente se obtiene encontrando la longitud en binario de la parte entera y convirtiendo a binario mediante corrimientos
	*La parte entera se obtiene su representación mediante corrimientos.
	*La parte fraccionaria se obtiene su representación multiplicando por dos repetitivamente partes fraccionarias, y almacenando las partes enteras de las multiplicaciones hasta que se llenen los 32 bits límit de la representación, o hasta encontrar un patrón de repetición
	*El método se detiene al obtener la representación completa o hasta agotar los 32 bits de representación posibles
	*/

	private void buildBinary(){
		List<Float> tmp = new ArrayList<Float>();
		long integ = (long)Math.abs(num);
		long exponent = (long)Math.floor(Math.log(Math.abs(integ))/Math.log(2));
		float el = num - integ;
		//Sign bit
		binary.add(num<0);
		//Binary exponent
		for(int i=7;i>=0;i--)
			binary.add((((exponent+127)>>i)&1)==1);
		//Binary integer
		for(long i=exponent-1;i>=0&&binary.size()<32;i--)
			binary.add(((integ>>i)&1)==1);
		//Binary fraction
		while(binary.size()<32&&tmp.indexOf(el)==-1){
			tmp.add(el);
			el=el*2;
			binary.add(Math.abs(el)>=1);
			el=el- (long)el;
		}
		for(int i=0;i<32-binary.size();i++)
			binary.add(false);
	}
	private void buildFloat(){
		int exponent=0;
		num=1;
		for(int i=1;i<9;i++)
			exponent+=binary.get(i)?Math.pow(2,9-i-1):0;
		for(int i=9;i<32;i++)
			num+=binary.get(i)?1/Math.pow(2,i-8):0;
		num*=Math.pow(2,exponent-127)*(binary.get(0)?-1:1);
		
	}
	private void buildList(String bin){
		System.out.println(bin.length());
		for(int i=0;i<bin.length();i++)
			binary.add(bin.charAt(i)=='1');
			
	}

	/*public String toString()
	*Genera la representación en cadena de texto del objeto FloatBinary
	*
	*Devuelve:
	*String str, representación String de FloatBinary
	*/
	public String toString(){
		String str="";
		str="num: "+num+"\n";
		for(int i=0;i<binary.size();i++)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}
}