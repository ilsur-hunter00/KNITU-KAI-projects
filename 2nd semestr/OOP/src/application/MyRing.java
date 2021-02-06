package application;
import javafx.scene.control.Alert;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;

public class MyRing {

	MyPoint point;
	MyCircle circle1, circle2;
	int count, count0;
	Label label;
	
	Canvas cnv;
	GraphicsContext gc;
	
	Alert alert;
	
	void doAlert(String text) {
		alert = new Alert(Alert.AlertType.INFORMATION);
		alert.setHeaderText(null);
		alert.setContentText(text);
		alert.showAndWait();
	}
	
	void show(boolean sh) {
		if (sh) {
			circle1.show(true);
			circle2.show(false);
		}
		else {
			circle1.show(false);
			circle2.show(false);
		}
	}
	
	void moveTo(double dx, double dy) {
		this.show(false);
		point.X += dx;
		point.Y += dy;
		circle1.checkBorder(dx, dy);		
		this.show(true);
	}
	
	void change(double p) {
		if (circle1.checkForResize(p)) {
			this.show(false);
			this.circle2.radius -= this.circle1.radius - p;
			this.circle1.radius = p;
			this.show(true);
		}
	}
	
	void delete() {
		this.show(false);
	}
	
	void ID(boolean t) {
		
		if (t) {
			gc.setFill(Color.CHARTREUSE);
			gc.fillOval(
	        	this.point.X-this.circle1.radius, this.point.Y-this.circle1.radius, 2*this.circle1.radius, 2*this.circle1.radius);
			circle2.show(false);
		}
		else {
			this.show(true);
		}
	}
	
	void mythread() {
		MyThread mt = new MyThread(label);
		Thread newThread = new Thread(mt);
		newThread.start();
	}
	
	MyRing(MyPoint Point) {
		
		this.point = Point;
		this.count = 0;
	}
	
	MyRing(MyPoint Point, MyCircle Circle1, MyCircle Circle2, int c, int c0, Canvas cnv, GraphicsContext gc, Label lb) {
		
		this.point = Point;
		this.circle1 = Circle1;
		this.circle2 = Circle2;
		this.count = c;
		this.count0 = c0;
		this.cnv = cnv;
		this.gc = gc;
		this.label = lb;
		
		mythread();
	}
}
