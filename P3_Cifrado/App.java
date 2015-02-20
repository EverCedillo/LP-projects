import java.util.*;
class App {
	public static void main(String[] args) {
		Encryption en = new Encryption();
		System.out.println(en.toString());
	}
	
}

class Encryption{
	public static final String alphabet[]={"a","b","c","d","e","f","g","h"};
	String[] key = new String[alphabet.length];
	Encryption(){
		buildKey();
	}	
	void buildKey(){
		List<String> temp=Arrays.asList(alphabet.clone());
		Collections.shuffle(temp);
		temp.toArray(key);
	}
	public String toString(){
		String str="";
		for(int i=0;i<8;i++)
			str=str+" "+alphabet[i]+"-"+key[i];
		return str;
	}
}