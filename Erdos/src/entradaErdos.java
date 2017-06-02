import java.util.*;
//import java.awt.*;

public class entradaErdos {

	public static void main(String[] args) {
		int scen, p, n;
		Scanner reader = new Scanner(System.in);
		String lin, linnum = "";
		String [] arrnum;
		ArrayList<String> arr = new ArrayList<String>();
		System.out.println("ingresa wiri wiwi: ");
		scen = Integer.parseInt(reader.nextLine());
		linnum = reader.nextLine();
		arrnum = linnum.split(" ");
		p = Integer.parseInt(arrnum[0]);
		n = Integer.parseInt(arrnum[1]);
		String [][] arr2 = new String[p][10];
		for(int i = 0; i < scen; i++){
			for(int j = 0; j < p; j++){
				lin = reader.nextLine();
				arr.add(lin);
			}
		}
		Iterator<String> iter = arr.iterator();
		int a = 0;
		int b = 0;
		while(iter.hasNext()){
			String elemento = iter.next();
			arr2[a] = elemento.split(",");
			a++;
			//System.out.print(elemento+" / ");
		}
		System.out.println(arr2[0][0]+" "+arr2[0][2]+" "+arr2[0][4]+" "+arr2[1][0]+" "+arr2[1][2]+" "+arr2[2][0]+" "+arr2[2][2]);
		//System.out.println(lin+" "+linnum+" "+p+" "+n);
		reader.close();
		
		
	}

}
