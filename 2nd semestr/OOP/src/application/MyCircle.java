package application;

import javafx.scene.canvas.Canvas;
import javafx.scene.control.Alert;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;
import javafx.scene.control.Label;

public class MyCircle {

	MyPoint point;
	double radius;
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
			gc.setFill(Color.BLUE);
			gc.fillOval(point.X-this.radius, point.Y-this.radius, 2*this.radius, 2*this.radius);
		}
		else {
			gc.setFill(Color.AQUAMARINE);
			gc.fillOval(point.X-(this.radius+1), point.Y-(this.radius+1), 2*(this.radius+1), 2*(this.radius+1));
		}
	}
	
	void showFigure(double arc1, double arc2) {
		gc.setFill(Color.AQUAMARINE);
		gc.fillArc(point.X-2*this.radius, point.Y-2*this.radius, 2*this.radius, 2*this.radius, arc1, arc2, ArcType.ROUND);
	}
	
	void checkBorder(double dx, double dy) {
		if (cnv.getWidth()-point.X < radius) this.point.X -= dx;
		else if (point.X < radius) this.point.X -= dx;
		else if (cnv.getHeight()-point.Y < radius) this.point.Y -= dy;
		else if (point.Y < radius) this.point.Y -= dy;
	}
	
	void moveTo(double dx, double dy) {
		this.show(false);
		point.X += dx;
		point.Y += dy;
		checkBorder(dx, dy);
		this.show(true);
	}
	
	void change(double p) {
		if (checkForResize(p)) {
			this.show(false);
			this.radius = p;
			this.show(true);
		}
	}
	
	void delete() {
		this.show(false);
	}
	
	void ID(boolean t) {
		if (t) {
			gc.setFill(Color.CHARTREUSE);
			gc.fillOval(this.point.X-this.radius, this.point.Y-this.radius, 2*this.radius, 2*this.radius);
		}
		else this.show(true);
	}
	
	boolean checkForResize(double R) {
		if ((cnv.getWidth()-point.X < R) || (point.X < R) || (cnv.getHeight()-point.Y < R) || (point.Y < R)) {
			doAlert("Изменения невозможны, фигура выходит за рамки поля!");
			return false;
		}
		else return true;
	}
	
	void mythread() {
		MyThread mt = new MyThread(label);
		Thread newThread = new Thread(mt);
		newThread.start();
	}
	
	MyCircle(MyPoint Point, double r, Canvas cnv, GraphicsContext gc) {
		
		this.point = Point;
		this.radius = r;
		this.cnv = cnv;
		this.gc = gc;
	}
	
	MyCircle(MyPoint Point, double r, int c, int c0, Canvas cnv, GraphicsContext gc, Label lb) {
		
		this.point = Point;
		this.radius = r;
		this.count = c;
		this.count0 = c0;
		this.cnv = cnv;
		this.gc = gc;
		this.label = lb;
		
		mythread();		
	}
}
