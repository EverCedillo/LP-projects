import java.util.Vector;
class App {
	public static void main(String[] args) {
		int n=127;
		Binary obj = new Binary(n);
		System.out.println(new Binary(n).toString()+"\n"+obj.twosComplement().toString());
	}
}

class Binary {
	int num;
	Vector<Boolean> binary = new Vector<Boolean>();
	Binary(int num){
		this.num=num;
		buildBinary();
	}
	void buildBinary(){
		for(int i=0;i<Math.floor(Math.log(Math.abs(num))/Math.log(2))+1;i++)
			binary.add(((num>>>i)&1)==1);
	}
	Binary twosComplement(){
		int com=~num;
		return new Binary(com+1);
	}
	public String toString(){
		String str="";
		for(int i=binary.size()-1;i>=0;i--)
			str=str+""+(binary.get(i)?1:0);
		return str;
	}

}