#include "wallpaper.h"
#include <QLoggingCategory>
#include <QDBusMessage>
#include <qdbusconnection.h>
#include <qloggingcategory.h>
#include <QDBusPendingReply>
Q_LOGGING_CATEGORY(XdgDesktopDDEWallpaper, "xdg-dde-wallpaper")

WallPaperPortal::WallPaperPortal(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
}
uint WallPaperPortal::SetWallpaperUrI(const QDBusObjectPath &handle,
                                      const QString &app_id,
                                      const QString &parent_window,
                                      const QString &url,
                                      const QVariantMap &options)
{
    qCDebug(XdgDesktopDDEWallpaper) << "Start set wallpaper";
    QDBusMessage msg = QDBusMessage::createMethodCall(QStringLiteral("org.deepin.daemon.Appearance"),
                                                      QStringLiteral("/org/deepin/daemon./Appearance"),
                                                      QStringLiteral("com.deepin.daemon.Appearance"),
                                                      QStringLiteral("SetMonitorBackground"));
    msg.setArguments({QVariant::fromValue(parent_window), QVariant::fromValue(url)});
    QDBusPendingReply<> pcall = QDBusConnection::sessionBus().call(msg);
    if (pcall.isValid()) {
        qCDebug(XdgDesktopDDEWallpaper) << "setting succeed";
        return 0;
    }
    qCDebug(XdgDesktopDDEWallpaper) << "setting failed";

    return 1;
}
