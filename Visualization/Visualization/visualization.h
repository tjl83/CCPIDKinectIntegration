#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <vector>
#include <QtWidgets/QMainWindow>
#include <QGraphicsEllipseItem>
#include "ui_visualization.h"

#include "KinectInterface.h"
#include "TrackedUser.h"

class Visualization : public QMainWindow
{
	Q_OBJECT

public:
	Visualization(QWidget *parent = 0);
	~Visualization();

private:
	Ui::VisualizationClass ui;
	QGraphicsScene *scene;
	QGraphicsScene *scene2;
	QGraphicsEllipseItem *ellipse;
	QGraphicsEllipseItem *leftHand;
	QGraphicsEllipseItem *rightHand;

	bool stop = false;

	KinectInterface* kinect;
	TrackedUser trackedUser;
	bool rightFirst = false, leftFirst = false;
	float jitter = .0005;
	qreal zfactor = 1;
	void moveEllipse();

private slots:
void on_pushbutton_start_clicked();
void on_pushbutton_stop_clicked();
};

#endif // VISUALIZATION_H
