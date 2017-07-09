import java.util.*;
public class main {
	private static String datos,linea;
	private static Integer nCities, nTrans,nX,nY,nD,from,to,many;
	private static int[][] dist;
	private static String[] sDates,sTrans;
	public static void main(String args[]){
		Scanner reader = new Scanner(System.in);
		System.out.println("Entrada:");
		int scen = 1;
		do{
			datos = reader.nextLine();
			sDates = datos.split(" ");
			nCities = Integer.parseInt(sDates[0]);
			nTrans = Integer.parseInt(sDates[1]);
			dist = new int[nCities][nCities];
			for(int i=nTrans;i>0;i--){
				linea = reader.nextLine();
				sTrans = linea.split(" ");
				nX = Integer.parseInt(sTrans[0]);
				nY = Integer.parseInt(sTrans[1]);
				nD = Integer.parseInt(sTrans[2]);
				dist[nX-1][nY-1]=dist[nY-1][nX-1] = nD;
			}
			linea = reader.nextLine();
			sDates= linea.split(" ");
			from = Integer.parseInt(sDates[0]);
			to = Integer.parseInt(sDates[1]);
			many = Integer.parseInt(sDates[2]);
			for(int q=0;q<nCities;q++){
				//System.out.println(">"+q);
				for(int w=0;w<nCities;w++){
				//	System.out.print(">>>[");
					for(int e=0;e<nCities;e++){
						dist[w][e]=Math.max(dist[w][e],Math.min(dist[w][q],dist[q][e]));
					//	System.out.print(dist[w][e]+",");
					}
				//	System.out.println("]");
				}
			}
			int flow = dist[from-1][to-1]-1;
			int cont =0;
			while(many>0){
				many-=flow;
				cont++;
			}
			System.out.println("Scenario #"+scen);
			scen++;
			System.out.println("Minimun Number of Trips = "+cont);
			System.out.println();
		}while(!(reader.nextLine().equals("0 0")));
	}
}
