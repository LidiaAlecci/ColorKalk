package Classes;

public class Color{
	private	int r=0;
	private int g=0;
	private int b=0;
	public Color(int red, int green, int blue){
		r=red;
		g=green;
		b=blue;
		if(red>255) 
			r=255;
	    if(green>255) 
	    	g=255;
	    if(blue>255) 
	    	b=255;
	    if(red<0)
	    	r=0;
	    if(green<0)
	    	g=0;
	    if(blue<0)
	    	b=0;
	}
	public int getRed(){
		return r;
	}
	public int getGreen(){
		return g;
	}
	public int getBlue(){
		return b;
	}
	public String toString(){
		return "Color("+r+","+g+","+b+")";
	}
	public Color add(Color c2){
		int red=r+c2.getRed(), green=g+c2.getGreen(), blue=b+c2.getBlue();
	    return new Color(red,green,blue);
	}
	public Color minus(Color c2){
	    int red=r-c2.getRed(), green=g-c2.getGreen(), blue=b-c2.getBlue();
	    return new Color(red,green,blue);
	}
	public double luminance(){
		return ((0.299*r+0.587*g+0.114*b)/255)*100;
	}
	public double CpM(){
		return ((Math.max(Math.max(r,g),b))/255.0);
	}
	public Color complementary(){
		return new Color(255-r,255-g,255-b);
	}
	public Color MaxIntensity(){
		double cpm=CpM();
	    int red=(int) (cpm*r), green=(int) (cpm*g), blue=(int) (cpm*b);
	    return new Color(red,green,blue);
	}
	public Color MinIntensity(){
		int minimo=Math.min(Math.min(r,g),b);
		int red=r-minimo, green=g-minimo, blue=b-minimo;
	    return new Color(red,green,blue);
	}
	public Color LucePura(){
		int minimo=Math.min(Math.min(r,g),b);
		int red=r-minimo, green=g-minimo, blue=b-minimo;
		int mass=Math.max(Math.max(r,g),b);
	    if(mass==0)
	        return new Color(0,0,0);
	    if(red==mass){
	        red=255;
	        if(g==0){
	            double d=b*(255/mass);
	            blue=(int) d;
	        }else{
	            double d=g*(255/mass);
	            green=(int) d;
	        }
	    }else if(blue==mass){
	        blue=255;
	        if(g==0){
	            double d=r*(255/mass);
	            red=(int) d;
	        }else{
	            double d=g*(255/mass);
	            green=(int) d;
	        }
	    }else{
	        green=255;
	        if(b==0){
	            double d=r*(255/mass);
	            red=(int) d;
	        }else{
	            double d=b*(255/mass);
	            blue=(int) d;
	        }
	    }
	    return new Color(red,green,blue);
	}
	public boolean is_Primary(){
		if((r!=0 && b==0 && g==0) ||
	            (b!=0 && r==0 && g==0) ||
	            (g!=0 && b==0 && r==0) ||
	            (b==0 && g==0 &&r==0) )
	        return true;
	    else
	        return false;
	}
	public boolean is_Secondary(){
		if((r!=0 && b!=0 && g==0) ||
	            (g!=0 && r!=0 && b==0) ||
	            (g!=0 && b!=0 && r==0) )
	        return true;
	    else
	        return false;
	}
	public boolean is_Tertiary(){
		if( r!=0 && b!=0 && g!=0)
			return true;
		else
			return false;
	}
}
