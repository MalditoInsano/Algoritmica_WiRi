import java.util.*;
public class main {
	private static Hashtable<String,String> diccionario = new Hashtable<String,String>();//Largo, 
	private static Hashtable<String,String> forzada = new Hashtable<String,String>();
	private static ArrayList<ArrayList<String>> lengths = new ArrayList<ArrayList<String>>(15);//Array de palabras de igual largo
	private static ArrayList<String[]> toDescifrar = new ArrayList<String[]>();//d
	private static ArrayList<String> array2 = new ArrayList<String>();
	private static String linea,word,toWord;
	private static String[] word1,word2;
	private static Integer cantidad;
	public static void main(String args[]){
		Scanner reader= new Scanner(System.in);
		setLenghts();
		System.out.println("Ingrese texto: ");
		linea = reader.nextLine();
		cantidad = Integer.parseInt(linea);
		for(int i=0;i<cantidad;i++){
			linea = reader.nextLine();
			System.out.println("----"+linea);
			(lengths.get(linea.length()-1)).add(linea);
		}
		linea = reader.nextLine();
		toDescifrar.add(linea.split(" "));
		linea = reader.nextLine();
		toDescifrar.add(linea.split(" "));
		for(int j=0;j<15;j++){
			
			ArrayList<String> list = (ArrayList<String>) lengths.get(j);
			if(list.size()>0){
				System.out.println("Largo: "+(j+1));
				System.out.print("        ");
				for(int k=0;k<list.size();k++){
					System.out.print(list.get(k)+"->");
				}
				System.out.println();
			}
			
		}
		reader.close();
		tryForzado();
		
	}
	public static void setLenghts(){
		for(int i=0;i<16;i++){	
			ArrayList<String> list = new ArrayList<String>();
			lengths.add(i,list);
		}
	}
	public static void tryForzado(){
		
		int contLineas =0;
		while(contLineas<toDescifrar.size()){
			boolean itWork = true;
			String[] lineaActual = (String[])toDescifrar.get(contLineas);
			int contWord =0;
			while(contWord<lineaActual.length && itWork){
				word = lineaActual[contWord];
				System.out.println(">>>>"+word+"<<<<<");
				ArrayList<String> posiblesWord = (ArrayList<String>) lengths.get(word.length()-1);
				if(posiblesWord.size()>0){
					int contPosible = 0;
					while(contPosible<posiblesWord.size() && diccionario.get(posiblesWord.get(contPosible))!=null){
						contPosible++;
					}
					if(contPosible<posiblesWord.size()){
						
						toWord=posiblesWord.get(contPosible);
						word1= word.split("(?!^)");
						word2=toWord.split("(?!^)");
						diccionario.put(toWord, word);
						for(int i=0;i<word.length();i++){
							if(forzada.get(word1[i])==null){
								forzada.put(word1[i], word2[i]);
								System.out.println(word1[i]+"="+word2[i]);
							}else{//Comprueba que no se asigen letras repetidas
								if(!(forzada.get(word1[i]).equals(word2[i]))){//Si existe y NO coinciden
									itWork=false;
									System.out.println("Falló por OverWriting en:"+word1[i]+"->"+forzada.get(word1[i])+"!="+word2[i]);
									diccionario.clear();
									forzada.clear();
									break;
								}
							}
						}
					}else if(contPosible<posiblesWord.size() && diccionario.get(posiblesWord.get(contPosible))==null){//verifica que haya a lo más la misma cantidad de palabras del mismo largo que puedan coincidir
						itWork=false;
						System.out.println("Falló por Falta de posibles palabras");
						diccionario.clear();
						forzada.clear();
						break;
					}
					
				}
				
				contWord++;
			}
			Descifrar(lineaActual);
			diccionario.clear();
			forzada.clear();
			contLineas++;
		}
	}
	public static void Descifrar(String[] linea){
		for(int i=0;i<linea.length;i++){
			String[] actual=linea[i].split("(?!^)");
			for(int j=0;j<actual.length;j++){
				if(forzada.get(actual[j])!=null){
					System.out.print(forzada.get(actual[j]));
				}else{
					System.out.print("*");
				}
			}
			System.out.print(" ");
		}
		System.out.println();
	}
}
