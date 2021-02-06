package application;

import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.paint.Color;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Label;

public class DescribedSquare {
	MyPoint point;
	MyCircle circle;
	MySquare square;
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
			square.show(true);
			circle.showFigure(0, -90);
		}
		else {
			square.show(false);
			circle.show(false);
		}
	}
	
	void moveTo(double dx, double dy) {
		this.show(false);
		point.X += dx;
		point.Y += dy;
		square.checkBorder(dx, dy);
		this.show(true);
	}
	
	void change(double p) {
		if (square.checkForResize(p)) {
			this.show(false);
			this.circle.radius -= (this.square.length - p)/2;
			this.square.length = p;
			this.show(true);
		}
	}
	
	void delete() {
		this.show(false);
	}
	
	void ID(boolean t) {
		if (t) {
			gc.setFill(Color.CHARTREUSE);
			gc.fillRect(point.X-this.square.length/2, point.Y-this.square.length/2, this.square.length, this.square.length);
			circle.showFigure(0, -90);
		}
		else this.show(true);
	}
	
	void mythread() {
		MyThread mt = new MyThread(label);
		Thread newThread = new Thread(mt);
		newThread.start();
	}
	
	DescribedSquare(MyPoint Point) {
		
		this.point = Point;
		this.count = 0;
	}
	
	DescribedSquare(MyPoint Point, MySquare Square, MyCircle Circle, int c, int c0, Canvas cnv, GraphicsContext gc, Label lb) {
		
		this.point = Point;
		this.square = Square;
		this.circle = Circle;
		this.count = c;
		this.count0 = c0;
		this.cnv = cnv;
		this.gc = gc;
		this.label = lb;
		
		mythread();
	}
}



