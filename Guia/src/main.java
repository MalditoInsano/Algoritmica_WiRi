import java.util.*;
public class main {
	private static String datos,linea;
	private static Integer nCities, nTrans,nX,nY,nD,from,to,many;
	private static int[][] dist;
	private static int[] pos;
	private static Stack st = new Stack();
	private static String[] sDates,sTrans;
	public static void main(String args[]){
		Scanner reader = new Scanner(System.in);
		System.out.println("Entrada:");
		datos = reader.nextLine();
		sDates = datos.split(" ");
		nCities = Integer.parseInt(sDates[0]);
		nTrans = Integer.parseInt(sDates[1]);
		dist = new int[nCities][nCities];
		for(int i=0;i<nTrans;i++){
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
		
	}
}
