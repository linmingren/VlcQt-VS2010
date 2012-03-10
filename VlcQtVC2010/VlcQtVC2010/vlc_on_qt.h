/* libVLC and Qt sample code
 * Copyright © 2009 Alexander Maringer <maringer@maringer-it.de>
 */
#ifndef VLC_ON_QT_H
#define VLC_ON_QT_H

#include <vlc/vlc.h>

#include <QtGui/QWidget>

class QVBoxLayout;
class QPushButton;
class QTimer;
class QFrame;
class QSlider;

#define POSITION_RESOLUTION 10000

class Player : public QWidget
{
    Q_OBJECT
    QSlider *_positionSlider;
    QSlider *_volumeSlider;
    // [20101201 Ondra Spilka] 
    // on Linux/Ubuntu Lucid and VLC >= 1.0 (at least 1.1.5 was tested) XWindow handle have to be passed
    // therefore QX11EmbedContainer have to be used instead of QFrame
#ifdef Q_WS_X11    
    QX11EmbedContainer *_videoWidget;
#else
    QFrame *_videoWidget;
#endif   
    QTimer *poller;
    bool _isPlaying;
   
    libvlc_instance_t *_vlcinstance;
    libvlc_media_player_t *_mp;
    libvlc_media_t *_m;

public:
    Player();
    ~Player();
    

public slots:
    void playFile(QString file);
    void updateInterface();
    void changeVolume(int newVolume);
    void changePosition(int newPosition);

};
#endif