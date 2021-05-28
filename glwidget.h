#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <limits>
#include "trackball.h";
#include "camera.h"
#include "light.h"
#include "material.h"
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    virtual ~GLWidget();
    
signals:
    void statusBarMessage(QString ns);
public slots:
    void toggleBackgroundColor(bool toBlack);
    void showFileOpenDialog();
    void animate();
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void wheelEvent(QWheelEvent * event);
    void keyPressEvent(QKeyEvent * event);
private:
    void readOFFFile(const QString &fileName);
    void genNormals();
    void genTexCoordsCylinder();
    void genTangents();
    void createShaders();
    void destroyShaders();

    QGLShader *vertexShader;
    QGLShader *fragmentShader;
    QGLShaderProgram *shaderProgram;
    unsigned int currentShader;

    unsigned int numVertices;
    unsigned int numFaces;
    QVector4D *vertices;
    QVector3D *normals;
    QVector2D *texCoords;
    QVector4D *tangents;
    unsigned int *indices;

    void createVBOs();
    void destroyVBOs();

    QGLBuffer *vboVertices;
    QGLBuffer *vboNormals;
    QGLBuffer *vboTexCoords;
    QGLBuffer *vboTangents;
    QGLBuffer *vboIndices;
    TrackBall trackBall;
    double zoom;
    QMatrix4x4 projectionMatrix;
    int texID[2];
    QTimer timer;
    Camera camera;
    Light light;
    Material material;

    QMatrix4x4 modelViewMatrix;

};

#endif // GLWIDGET_H
