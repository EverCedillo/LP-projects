/*****************
* Cedillo Martínez Jesús Everardo
* García González Brenda
*5 Feb 2014
******************/


import java.util.Vector;
import java.io.*;

/*
Class App
Clase principal donde se aplican los métodos de la clase Polinomio
*/
class App{
	public static void main(String[] args) {
		int gradeFirst, gradeSecond,option,point;
		Vector<Float>coef1;
		Vector<Float>coef2;
		do{
			System.out.println("Polinomios\n1.Valor en un punto\n2.Suma\n3.Resta\n4.Igualdad\n5.Polinomio opuesto\n6. Multiplicacion\n7. Salir");
			System.out.println("\nOption: ");
			option=Leer.datoInt();

			if (option==1||option==5){
				coef1 = new Vector<Float>();
				System.out.println("Ingresa el grado del polinomio");
				gradeFirst=Leer.datoInt();
				Polinomio pol1=new Polinomio(gradeFirst);
				for(int i=0;i<gradeFirst+1;i++){
					System.out.println("Ingresa el coeficiente de x^"+i+":");
					coef1.add((float)Leer.datoDouble());
				}
				pol1.setCoef(coef1);
				if(option==1){
					System.out.println("Ingresa el punto a evaluar");
					point=Leer.datoInt();
					System.out.println("El polinomio "+pol1.toString()+" evaluado es:\n"+pol1.eval(point));
				}else if(option==5){
					System.out.println("El polinomio opuesto de "+pol1.toString()+" es:\n"+pol1.oposite().toString());
				}
			}
			else if(option<7&&option>0){
				coef1 = new Vector<Float>();
				coef2 = new Vector<Float>();
				System.out.println("Ingresa el grado del polinomio uno");
				gradeFirst=Leer.datoInt();
				Polinomio pol1=new Polinomio(gradeFirst);
				for(int i=0;i<gradeFirst+1;i++){
					System.out.println("Ingresa el coeficiente de x^"+i+":");
					coef2.add((float)Leer.datoDouble());
				}
				System.out.println("Ingresa el grado del polinomio dos");
				gradeSecond=Leer.datoInt();
				Polinomio pol2=new Polinomio(gradeSecond);
				for(int j=0;j<gradeSecond+1;j++){
					System.out.println("Ingresa el coeficiente de x^"+j+":");
					coef1.add((float)Leer.datoDouble());
				}
				pol1.setCoef(coef1);
				pol2.setCoef(coef2);

				switch(option){
					case 2://Suma
						System.out.println("La suma de los polinomios\n"+pol1.toString()+" y \n"+pol2.toString()+ " es:\n"+pol1.sum(pol1,pol2).toString());
					break;
					case 3://Resta
						System.out.println("La resta de los polinomios\n"+pol1.toString()+" y \n"+pol2.toString()+ " es:\n"+pol1.substraction(pol1,pol2).toString());	
					break;

					case 4://Igualdad
						System.out.println("Los polinomios\n"+pol1.toString()+" y \n"+pol2.toString()+ "\nson "+(pol1.equals(pol2)?"iguales":"diferentes"));		
					break;
					case 6: //Multiplicacion
						System.out.println("La Multiplicacion de los polinomios\n"+pol1.toString()+" y \n"+pol2.toString() +" es:\n"+pol1.multi(pol1,pol2).toString());		
					break;
					default:
						//Nothin' to do
					break;

				}
			}

		}while(option!=7);
	}
}
/*
Class Polinomio
La clase polinomio contiene métodos para la realización de operaciones básicas
con polinomios de coeficientes reales, como lo son suma, resta, multipliación
polinomio opuesto y evaluación en un punto dado.

Contiene una lista de coeficientes cuya posición en la lista coincide con el exponente
al que multiplica
*/
class Polinomio {
	/*Vector<Float> coef, estructura tipo lista que contiene los coeficientes del polinomio
	** int grade, entero que representa el grado del polinomio */

	private Vector<Float> coef = new Vector<Float>();
	private int grade;
	Polinomio(){
	}
	/*
	Polinomio(int grade), constructor, recibe como parámetro el grado del polinomio y 
	crea la lista de coeficientes en cero.
	*/
	Polinomio(int grade){
		this.grade=grade;
		coef.setSize(grade+1);
		zeros();
	}
	/*
	public void zeros()
	método que vuelve todos los coeficientes del polinomio en cero
	*/
	public void zeros(){
		for (int i=0;i<grade+1;i++)
			coef.set(i,(float)0);
	}
	/*
	public void setCoef(Vector<Float> coef)
	Asigna el Vector coef al vector de coeficientes del polinomio
	y actualiza el grado del polinomio según la cantidad de elementos en coef
	Si el Vector está vacio los coeficientes no se ven afectados

	Recibe:
	Vector<Float> coef,	un Vector de elementos Float
	Devuelve
	void
	*/
	public void setCoef(Vector<Float> coef){
		if(coef.size()==0)
			return;
		grade=coef.size()-1;
		this.coef=coef;
	}
	/*
	public Polinomio sum(Polinomio pol1, Polinomio pol2)
	Realiza la suma de dos polinomios sumando los elementos de sus respectivos vectores 
	de coeficientes con indices coincidentes
	Recibe:
	Polinomio pol1 polinomio a sumar
	Polinomio pol2 polinomio a sumar
	Devuelve:
	Polinomio re, resultado de la suma de los parámetros
	*/
	public Polinomio sum(Polinomio pol1, Polinomio pol2){
		int maxGrade=pol2.getGrade()>pol1.getGrade()?pol2.getGrade():pol1.getGrade();
		int minGrade=pol2.getGrade()<pol1.getGrade()?pol2.getGrade():pol1.getGrade();
		Polinomio res = new Polinomio(maxGrade);
		res.setCoef(pol2.getGrade()>pol1.getGrade()?pol2.getCoef():pol1.getCoef());
		for(int i=0;i<minGrade+1;i++)
			res.getCoef().set(i,pol1.getCoef().get(i)+pol2.getCoef().get(i));
		return res;
	}
	/*
	public Polinomio substraction(Polinomio pol1, Polinomio pol2)
	Realiza la resta del primer parámetro menos el segundo auxiliandose del método oposite() 
	y del método sum(Polinomio pol1, Polinomio pol2).
	Recibe:
	Polinomio pol1 minuendo
	Polinomio pol2 sustraendo
	Devuelve:
	Polinomio res, resultado de la resta de pol1 - pol2
	*/
	public Polinomio substraction(Polinomio pol1, Polinomio pol2){
		Polinomio res=sum(pol1,pol2.oposite());
		return res;
	}
	/*
	public Polinomio multi(Polinomio pol1, Polinomio pol2)
	Reliza la multiplicación de éstos multiplicando cada elemento del primer vector
	de coeficientes, contra cada elemento del segundo, los polinomios resultados 
	de cada iteración se suman con el método sum()
	Recibe:
	Polinomio pol1 polinomio a multiplicar
	Polinomio pol2 polinomio a multiplicar
	Devuelve:
	Polinomio res, polinomio resultado de la multipliación pol1*pol2
	*/
	public Polinomio multi(Polinomio pol1, Polinomio pol2){
		int maxGrade=pol2.getGrade()>pol1.getGrade()?pol2.getGrade():pol1.getGrade();
		int minGrade=pol2.getGrade()<pol1.getGrade()?pol2.getGrade():pol1.getGrade();
		Polinomio res = new Polinomio(pol2.getGrade()+pol1.getGrade());
		Vector<Polinomio> polsMulti= new Vector<Polinomio>();
		for(int i=0;i<pol1.grade+1;i++){
			Polinomio temp = new Polinomio(pol2.getGrade()+i);
			for(int j=0;j<pol2.grade+1;j++)
				temp.getCoef().set(i+j,pol1.getCoef().get(i)*pol2.getCoef().get(j));
			polsMulti.add(temp);
		}
		while(polsMulti.size()>1)
			polsMulti.set(0,new Polinomio().sum(polsMulti.get(0),polsMulti.remove(1)));
		return polsMulti.get(0);
	}
	/*
	public int getGrade()
	Devuelve el grado del objeto Polinomio
	Devuelve:
	int grade, grado del polinomio
	*/
	public int getGrade(){
		return grade;
	}
	/*
	public String toString()
	devuelve una representación en cadena de texto del objeto polinomio
	Devuelve:
	String str
	*/
	public String toString(){
		String str="";
		for(int i=0;i<grade+1;i++)
			str=str+(coef.get(i)<0?"":"+")+(coef.get(i)==0.0?coef.get(i)+0.0:coef.get(i))+"*x^"+i+" ";
		return str;
	}
	/*
	public float eval(double val)
	Realiza la evaluación del polinomio en un punto
	Recibe:
	double val, número real a evaluar en el polinomio
	Devuelve:
	float res, valor del polinomio en ese punto
	*/
	public float eval(double val){
		float res=0;
		for(int i=0;i<coef.size();i++)
			res+=Math.pow(val,i)*coef.get(i);
		return res;
	}
	/*
	public boolean equals(Polinomio pol)
	Verifica la igualdad de dos objetos polinomio, la igualdad es verdadera cuando los elementos 
	de sus coeficientes son los mismos en el mismo orden
	Recibe:
	Polinomio pol, polinomio a comparar
	*/
	public boolean equals(Polinomio pol){
		return pol.getCoef().equals(coef);
	}
	/*
	public Vector<Float> getCoef()
	Retorna el vector de coeficientes del polinomio
	Devuelve:
	Vector<Float> coef, vector de coeficientes
	*/
	public Vector<Float> getCoef(){
		return coef;
	}
	/*
	public Polinomio oposite()
	Genera el polinomio opuesto
	Devuelve:
	Polinomio neg, polinomio opuesto
	*/
	public Polinomio oposite(){
		Polinomio neg=new Polinomio(grade);
		Vector<Float> neg_coef=new Vector<Float>();
		for(int i=0;i<grade+1;i++)
			neg_coef.add(coef.get(i)*-1);
		neg.setCoef(neg_coef);
		return neg;
	}
}	

/*
Class Leer
clase auxiliar para la lectura desde teclado
*/

class Leer
{
	public static String dato ()
	{
		String str="";

		InputStreamReader isr = new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader (isr);

		try {
		
			str= br.readLine ();
		    }
		catch (IOException e) {
			System.out.println ("Error de la lectura. "+e.getMessage());
		   }
		return str;
	}

	public static double datoDouble ()
	{
		try {
			return Double.parseDouble (dato());
		}
		catch (NumberFormatException e) {
			return Double.MIN_VALUE;
		}
	}

	public static int datoInt()
	{
		try {
			return Integer.parseInt (dato());
		}
		catch (NumberFormatException e) {
			return Integer.MIN_VALUE;
		}
	}
			
}