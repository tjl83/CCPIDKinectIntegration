#include "visualization.h"
#include <math.h>

Visualization::Visualization(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new QGraphicsScene(this);

	ui.graphicsView->setScene(scene);

	QPen blackpen(Qt::black);
	blackpen.setWidth(1);
	QBrush blueBrush(Qt::blue);
	QBrush redBrush(Qt::red);

	ellipse = scene->addEllipse(0, 0, 100, 100, blackpen, redBrush);

	scene2 = new QGraphicsScene(this);

	ui.graphicsView_2->setScene(scene2);

	leftHand = scene2->addEllipse(30, 0, 10, 10, blackpen, blueBrush);
	rightHand = scene2->addEllipse(-30, 0, 10, 10, blackpen, blueBrush);

	ui.pushbutton_stop->setEnabled(false);

	kinect = new KinectInterface();
}

Visualization::~Visualization()
{

}

using namespace std;
void Visualization::on_pushbutton_start_clicked(){
	statusBar()->showMessage("Initializing Sensor", 2000);
	int sensorState = kinect->init();

	if (FAILED(sensorState))
	{
		statusBar()->showMessage("Sensor Not Found", 2000);
		return;
	}
	else
	{
		statusBar()->showMessage("Sensor Found!", 2000);
		ui.pushbutton_start->setEnabled(false);
		ui.pushbutton_stop->setEnabled(true);
	}

	statusBar()->showMessage("Acquiring Data", 2000);

	int counter = 0;

	while (kinect->hasNextFrame() && !stop)
	{
		if (kinect->getUsers().empty()){
			continue;
		}
		bool tracked = false;
		for (NUI_USER_INFO user : kinect->getUsers())
		{
			if (trackedUser.getID() == user.SkeletonTrackingId){
// 				statusBar()->showMessage("Tracked User found!", 2000);
				trackedUser.updateHands(user);
				tracked = true;
				break;
			}
		}

		if (!tracked){
// 			statusBar()->showMessage("New User found!", 2000);
			trackedUser = TrackedUser(kinect->getUsers().front());
		}

		Coordinate left = trackedUser.getCurrPos(NUI_HAND_TYPE_LEFT);
		if (left.y() < 2){
			if (trackedUser.getGripped(NUI_HAND_TYPE_LEFT)){
				if (!rightFirst){
					leftFirst = true;
				}
				ui.lineEdit_status_l->setText("Gripped");
				ui.lineEdit_x_l->setText(to_string(left.x()).c_str());
				ui.lineEdit_y_l->setText(to_string(left.y()).c_str());
				ui.lineEdit_z_l->setText(to_string(left.z()).c_str());
			}
			else{
				if (leftFirst){
					leftFirst = false;
				}
				ui.lineEdit_status_l->setText("Not tracked: Open");
				ui.lineEdit_x_l->clear();
				ui.lineEdit_y_l->clear();
				ui.lineEdit_z_l->clear();
			}
		}
		else{
			leftFirst = false;
			ui.lineEdit_status_l->setText("Not tracked: Out of Scope");
			ui.lineEdit_x_l->clear();
			ui.lineEdit_y_l->clear();
			ui.lineEdit_z_l->clear();
		}

		Coordinate right = trackedUser.getCurrPos(NUI_HAND_TYPE_RIGHT);
		if (right.y() < 2){
			if (trackedUser.getGripped(NUI_HAND_TYPE_RIGHT)){
				if (!leftFirst){
					rightFirst = true;
				}
				ui.lineEdit_status_r->setText("Gripped");
				ui.lineEdit_x_r->setText(to_string(right.x()).c_str());
				ui.lineEdit_y_r->setText(to_string(right.y()).c_str());
				ui.lineEdit_z_r->setText(to_string(right.z()).c_str());
			}
			else{
				if (rightFirst){
					rightFirst = false;
				}
				ui.lineEdit_status_r->setText("Not tracked: Open");
				ui.lineEdit_x_r->clear();
				ui.lineEdit_y_r->clear();
				ui.lineEdit_z_r->clear();
			}
		}
		else{
			rightFirst = false;
			ui.lineEdit_status_r->setText("Not tracked: Out of Scope");
			ui.lineEdit_x_r->clear();
			ui.lineEdit_y_r->clear();
			ui.lineEdit_z_r->clear();
		}

		if (leftHand->pos().y() + left.y() * 50 < 100){
			leftHand->setX(left.x() * 50 - 50);
			leftHand->setY(left.y() * 50);
		}
		if (rightHand->pos().y() + right.y() * 50 < 100){
			rightHand->setX(right.x() * 50 + 50);
			rightHand->setY(right.y() * 50);
		}

		statusBar()->showMessage(std::to_string(leftHand->pos().y()).c_str());

		moveEllipse();

		QCoreApplication::processEvents();
	}
}

void Visualization::moveEllipse(){
	NUI_HAND_TYPE hand = NUI_HAND_TYPE_NONE;
	if (leftFirst){
		hand = NUI_HAND_TYPE_LEFT;
	}
	else if (rightFirst){
		hand = NUI_HAND_TYPE_RIGHT;
	}
	else{
		return;
	}

	Coordinate curr = trackedUser.getCurrPos(hand);
	Coordinate prev = trackedUser.getPrevPos(hand);
	float newX = curr.x() - prev.x(), newY = curr.y() - prev.y(), newZ = curr.z() - prev.z();

	if ((-300 < (ellipse->pos().x() + newX * 500) && (ellipse->pos().x() + newX * 500) < 350) &&
		(-220 < (ellipse->pos().y() + newY * 500) && (ellipse->pos().y() + newY * 500) < 90))
		ellipse->moveBy(newX * 500, newY * 500);
}

void Visualization::on_pushbutton_stop_clicked(){
	stop = true;
	ui.pushbutton_start->setEnabled(true);
	ui.pushbutton_stop->setEnabled(false);
}