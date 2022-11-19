#import pyrebase
# import firebase
from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 800)
        MainWindow.setMinimumSize(QtCore.QSize(800, 800))
        MainWindow.setMaximumSize(QtCore.QSize(800, 800))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setObjectName("widget")
        self.BLUE = QtWidgets.QLabel(self.widget)
        self.BLUE.setGeometry(QtCore.QRect(103, 0, 50, 50))
        self.BLUE.setMinimumSize(QtCore.QSize(50, 50))
        self.BLUE.setMaximumSize(QtCore.QSize(50, 50))
        self.BLUE.setBaseSize(QtCore.QSize(50, 50))
        self.BLUE.setPixmap(QtGui.QPixmap("D:/Projects/GP-SBME2021/Layers/Ellipse 1.png"))
        self.BLUE.setScaledContents(True)
        self.BLUE.setObjectName("BLUE")
        self.Map = QtWidgets.QLabel(self.widget)
        self.Map.setGeometry(QtCore.QRect(-10, -10, 791, 791))
        self.Map.setPixmap(QtGui.QPixmap("D:/Projects/GP-SBME2021/Final_Map.png"))
        self.Map.setScaledContents(True)
        self.Map.setObjectName("Map")
        self.Map.raise_()
        self.BLUE.raise_()
        self.gridLayout.addWidget(self.widget, 0, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)

        # self.action.trigger.connect(lambda: self.move(X_VALUE, Y_VALUE)) # The new line should be like that...
        self.move(450, 300)
        
        config = {
                "apiKey": "AIzaSyDVTWUxzpbK4ud3xMUzBA_O9nTbnH0wuS4",
                "authDomain": "localization-e4a0f.firebaseapp.com",
                "databaseURL": "https://localization-e4a0f.firebaseio.com",
                "storageBucket": "localization-e4a0f.appspot.com"
                }

        # firebase = firebase.initialize_app(config)

        # self.db = firebase.database()

        self.retranslateUi(MainWindow)
    
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def get_value(self):
            # temp = self.db.child("sector").get()
            return temp.val()

    def move(self, x, y):
        self.BLUE.setGeometry(QtCore.QRect(x, y, 50, 50))

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())