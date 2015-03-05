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
		List<Float> tmp = new ArrayList<Float>();
		long integ = (long)Math.abs(num);
		long index = (long)Math.floor(Math.log(Math.abs(integ))/Math.log(2));
		float frac = num - integ;
		float el = frac;
		//binary.add(Math.abs(el)>=1);

		binary.add(num<0);
		for(int i=7;i>=0;i--)
			binary.add((((index+127)>>i)&1)==1);
		for(long i=index;i>=0;i--)
			binary.add(((integ>>i)&1)==1);

		while(tmp.size()<23&&tmp.indexOf(el)==-1){
			//System.out.println(el+"--\n");
			
			tmp.add(el);
			System.out.println(el+"--tmp\n");
			el=el*2;
			binary.add(Math.abs(el)>=1);
			System.out.println(el+"--bool\n");
			el=el- (long)el;
			//System.out.println(el+"\n");
		}
	}
	public String toString(){
		String str="";
		for(int i=0;i<binary.size();i++)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}
}