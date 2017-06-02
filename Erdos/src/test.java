import java.util.Hashtable;
import java.util.Scanner;
import java.util.Stack;
public class test {
	public static void main(String[] args){
		/*{{"Smith","Martin","Erdos"},
				          {"Erdos","Reisig",null},
					      {"Smith","Chen",null},
						  {"Jablonski","Hsueh",null}};*/
		Scanner reader = new Scanner(System.in);
		int scen,p,n;
		System.out.println("ingrese wiri");
		scen = Integer.parseInt(reader.nextLine());
		String linnum = reader.nextLine(),lin;
		String [] arrnum = linnum.split(" ");
		p = Integer.parseInt(arrnum[0]);
		n = Integer.parseInt(arrnum[1]);
		for(int i =1;i<=scen;i++){
			System.out.println("escena: "+i);
			String[][] names = namesInput(reader,p);
			Stack out = stackNames(reader, n);//Stack de salida, aquí van los nombres a mostrar
			Hashtable<String, Integer> numErdos = numberGenerator(names);
			imprimir(out,numErdos);	
		}
		
	}
	public static void imprimir(Stack out, Hashtable<String,Integer> numErdos){
		String name;
		System.out.println("Salida:");
		while(!out.empty()){
			name= (String) out.pop();
			if(numErdos.get(name)!=null){
				System.out.println(name+" "+numErdos.get(name));
			}
			else{
				System.out.println(name+" infinity");
			}
		}
	}
	public static String[][] namesInput(Scanner s,int p){
		String lin,lin2;
		int index;
		String[][] names = new String[p][10];
		String[][] rec = new String[p][10];
		String [] arr3 = new String[p];
		System.out.println("linea de nombres:");
		for(int j = 0; j < p; j++){
			lin = s.nextLine();
			rec[j] = lin.split(",");
			index = (rec[j].length)-1;
			for(int z=0;z<(index/2);z++){
				lin2=((rec[j][2*z].concat(",")).concat(rec[j][(2*z)+1])).trim();
				System.out.println(lin2);
				names[j][z]=lin2;
			}
			
		}
		return names;
	}
	public static Stack stackNames(Scanner s,int n){
		Stack out = new Stack();
		String linea;
		System.out.println("Stack de nombres out:");
		for(int i =0;i<n;i++){
			linea = s.nextLine();
			System.out.println("    "+linea);
			out.push(linea);
		}
		return out; 
	}
	
	public static Hashtable<String,Integer> numberGenerator(String[][] names){
		Hashtable<String, Integer> numErdos = new Hashtable<String, Integer>();
		numErdos.put("Erdos, P.", 0);
		Stack nR = new Stack();//Stack noRegistrados
		Stack aB = new Stack();//Stack aBuscar
		aB.push("Erdos, P.");
		int p =4;//Cantidad de Articulos (líneas)
		String toSearch, actual;
		System.out.println("begin");
		System.out.println("   Erdos: "+(numErdos.get("Erdos, P.")));
		while(!aB.empty()){
		    toSearch = (String) aB.pop();
		    System.out.println("String A Buscar: "+toSearch);
					for(int i=0;i<p;i++){
					int pos =0;//posición de la fila i
					boolean k = false;//determina si el stack nR actual debe ser registrado
					do{
						actual = (names[i][pos]);
							if(actual.equals(toSearch)){
								k=true;
								System.out.println("true");
							}else if(numErdos.get(actual)==null){	
								nR.push(actual);
							}
						pos++;
					}while(pos<3 && names[i][pos]!=null);
		
					while(!nR.empty()){
							System.out.println(" no está vacío");
							actual = (String) nR.pop();
							if(k){
								aB.push(actual);
								numErdos.put(actual, (numErdos.get(toSearch))+1);
							}
					}
				}
		}
		return numErdos;
	}
}
