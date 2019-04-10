#ifndef QTSIMPLELOG_H
#define QTSIMPLELOG_H

FILE *output = stdout;

#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
/* Qt4版本写法 */
void outputRedirection(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        fprintf(output, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
        fprintf(output, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        fprintf(output, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        fprintf(output, "Fatal: %s\n", msg);
        abort();
    }
}
#else
/* Qt5版本写法 */
void outputRedirection(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(output, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(output, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(output, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(output, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(output, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}
#endif

#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
#define QT_SIMPLE_LOG do {\
    output = fopen("output.txt", "a"); \
    qInstallMsgHandler(outputRedirection); }while(0);
#else
#define QT_SIMPLE_LOG qInstallMessageHandler(outputRedirection);
#endif

#endif // QTSIMPLELOG_H
