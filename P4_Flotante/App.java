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

class FloatBinary {
	float num;
	List<Boolean> binary=new ArrayList<Boolean>();
	FloatBinary(float num){
		this.num=num;
		buildBinary();
	}
	void buildBinary(){
		long integ = (long)Math.abs(num);
		long index = (long)Math.floor(Math.log(Math.abs(integ))/Math.log(2));
		float frac = num - integ;
		for(int i=0;i<index+1;i++)
			binary.add(((integ>>i)&1)==1);
		for(int i=0;i<8;i++)
			binary.add((((index+127)>>i)&1)==1);
		binary.add(num<0);
	}
	public String toString(){
		String str="";
		for(int i=binary.size()-1;i>=0;i--)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}
}