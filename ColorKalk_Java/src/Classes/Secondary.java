package Classes;

public class Secondary extends ColorType{
	public Secondary(int red, int green, int blue){
		super(red,green,blue);	
	}
	public Primary getSecondPrimary(){
	    int red=getRed(), green=getGreen(), blue=getBlue();
	    if(red!=0 && green!=0)
	        return new Primary(0,green,0);
	    else
	        return new Primary(0,0,blue);

	}
}
