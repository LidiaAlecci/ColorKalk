package Main;

import Classes.*;

public class Use {
	public static void main(String[] arg){
		System.out.println("Start");
		ColorType p=new Primary(0,150,0);
		ColorType s= new Secondary(0,2,270);
		ColorType t= new Tertiary(140,90,200);
		System.out.print(p+"+"+s+"=");
		ColorType r1=(ColorType) p.add(s);
		System.out.println(r1+" che è un "+r1.getClass()+".");
		System.out.println(r1+" è formato dal primo primario "+r1.getFirstPrimary()+", " +
				"e dal secondo primario "+((Secondary)r1).getSecondPrimary()+".");
		System.out.println(t+" è formato dal primario "+t.getFirstPrimary()+
				", e dal secondario "+((Tertiary)t).getSecondary()+".");
		System.out.println("Il complementare di "+t+" è "+t.complementary()+".");
		System.out.println("Luce Pura di "+t+" è "+t.LucePura()+".");
		System.out.println("Colore ad intensità massima di "+t+" è "+t.MaxIntensity()+".");
		System.out.println("Colore ad intensità minima di "+t+" è "+t.MinIntensity()+".");
		System.out.println("La differenza tra "+s+"-"+t+" è "+s.minus(t)+".");
		System.out.println("End");
	}

}
