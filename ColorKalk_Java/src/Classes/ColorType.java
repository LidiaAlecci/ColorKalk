package Classes;

public abstract class ColorType extends Color{
	public ColorType(int red, int green, int blue){
		super(red,green,blue);	
	}
	private ColorType buildColorType(Color c){
		int red=c.getRed(), green=c.getGreen(), blue=c.getBlue();
	    if(c.is_Primary()){
	        return new Primary(red,green,blue);
	    }else if(c.is_Secondary()){
	        return new Secondary(red,green,blue);
	    }else{
	        return new Tertiary(red,green,blue);
	    }
	}
	public ColorType getFirstPrimary(){
		int red=getRed(), green=getGreen(), blue=getBlue();
	    if(red!=0)
	        return new Primary(red,0,0);
	    if(green!=0)
	        return new Primary(0,green,0);
	    else
	        return new Primary(0,0,blue);
	}
	public Color add(Color c2){
		Color c=super.add(c2);
		return buildColorType(c);
	}
	public Color minus(Color c2){
		Color c=super.minus(c2);
		return buildColorType(c);
	}
	public Color complementary(){
		Color c=super.complementary();
		return buildColorType(c);
	}
	public Color MaxIntensity(){
		Color c=super.MaxIntensity();
		return buildColorType(c);
	}
	public Color MinIntensity(){
		Color c=super.MinIntensity();
		return buildColorType(c);
	}
	public Color LucePura(){
		Color c=super.LucePura();
		return buildColorType(c);
	}
	
}
