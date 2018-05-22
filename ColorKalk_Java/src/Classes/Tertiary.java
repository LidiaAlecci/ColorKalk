package Classes;

public class Tertiary extends ColorType{
	public Tertiary(int red, int green, int blue){
		super(red,green,blue);	
	}
	public Secondary getSecondary(){
	    return new Secondary(0,getGreen(),getBlue());
	}
}

