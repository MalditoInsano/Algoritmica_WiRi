import java.util.*;
public static String datos;
public static Integer nCities, nTrans;
public class main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		datos=reader.nextLine();
		nCities = Integer.parseInt(datos.charAt(0));
		nTrans = Integer.parseInt(datos.charAt(2));
		System.out.println("Cities: "+nCities+" Trans: "+nTrans);
	}
}
