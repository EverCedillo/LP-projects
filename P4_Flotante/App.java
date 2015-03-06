import java.util.*;
import java.io.*;
class App {
	public static void main(String[] args) {
		InputStreamReader isr = new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader (isr);
		float data;
		FloatBinary fb;
		System.out.println("Escribe el numero");
		try{
			data=Float.parseFloat(br.readLine ());
		}catch (IOException e){
			data=0;
		}
		fb = new FloatBinary(data);
		System.out.println(fb.toString());
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
	List<Boolean> binary=new ArrayList<Boolean>();
	/*
	*Constructor
	*Recibe:
	*float num, numero a representar en bits
	*/
	FloatBinary(float num){
		this.num=num;
		buildBinary();
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
		long index = (long)Math.floor(Math.log(Math.abs(integ))/Math.log(2));
		float el = num - integ;
		//Sign bit
		binary.add(num<0);
		//Binary index
		for(int i=7;i>=0;i--)
			binary.add((((index+127)>>i)&1)==1);
		//Binary integer
		for(long i=index;i>=0&&binary.size()<32;i--)
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

	/*public String toString()
	*Genera la representación en cadena de texto del objeto FloatBinary
	*
	*Devuelve:
	*String str, representación String de FloatBinary
	*/
	public String toString(){
		String str="";
		for(int i=0;i<binary.size();i++)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}
}