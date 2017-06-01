import java.util.*;
public class main {
	public static void main(String[] args) {
		String[][] names = {{"Smith","Martin","Erdos"},
				          {"Erdos","Reisig",null},
					      {"Smith","Chen",null},
						  {"Jablonski","Hsueh",null}};
		
		Hashtable<String, Integer> numErdos = numberGenerator(names);
		Stack out = new Stack();//Stack de salida, aquí van los nombres a mostrar
		//Ejemplo de petición
		out.push("Erdos");
		out.push("Smith");
		out.push("Martin");
		out.push("Reisig");
		out.push("Chen");
		out.push("Jablonski");
		out.push("Hsueh");
		imprimir(out,numErdos);	
	}
	public static void imprimir(Stack out, Hashtable<String,Integer> numErdos){
		String name;
		while(!out.empty()){
			name= (String) out.pop();
			if(numErdos.get(name)!=null){
				System.out.println(name+": "+numErdos.get(name));
			}
			else{
				System.out.println(name+": infinity");
			}
		}
	}
	public static Hashtable<String,Integer> numberGenerator(String[][] names){
		Hashtable<String, Integer> numErdos = new Hashtable<String, Integer>();
		numErdos.put("Erdos", 0);
		Stack nR = new Stack();//Stack noRegistrados
		Stack aB = new Stack();//Stack aBuscar
		aB.push("Erdos");
		int p =4;//Cantidad de Articulos (líneas)
		String toSearch, actual;
		while(!aB.empty()){
		    toSearch = (String) aB.pop();
				for(int i=0;i<p;i++){
				int pos =0;//posición de la fila i
				boolean k = false;//determina si el stack nR actual debe ser registrado
				do{
					actual = names[i][pos];
						if(actual==toSearch){
							k=true;
						}else if(numErdos.get(actual)==null){	
							nR.push(actual);
						}
					pos++;
				}while(pos<3 && names[i][pos]!=null);

				while(!nR.empty()){
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
