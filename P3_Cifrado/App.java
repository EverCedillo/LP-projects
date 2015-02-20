import java.util.*;
class App {
	public static void main(String[] args) {
		Encryption en = new Encryption(new String());
		System.out.println(en.toString());
	}
	
}

class Encryption{
	public static final String ALPHABET[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","o","p","q","r","s","t","u","v","w","x","w","y","z"};
	private String[] key = new String[ALPHABET.length];
	String info;
	Encryption(String info){
		buildKey();
		this.info=info;
	}	
	void buildKey(){
		List<String> temp=Arrays.asList(ALPHABET.clone());
		Collections.shuffle(temp);
		temp.toArray(key);
	}
	void encrypt(){

	}
	public String toString(){
		String str="";
		for(int i=0;i<ALPHABET.length;i++)
			str=str+" "+ALPHABET[i]+"-"+key[i];
		return str;
	}
}