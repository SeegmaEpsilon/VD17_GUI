#include <mainwindow.h>
#include <ui_mainwindow.h>

/* Обрабатываем движение мыши */
void MainWindow::slotMouseMove(QMouseEvent* event)
{
  QCustomPlot* senderCanvas = qobject_cast<QCustomPlot*>(sender());
  if (!senderCanvas)
    return;

  QCPAxis* Haxis = senderCanvas->axisRect()->rangeDragAxis(Qt::Horizontal);
  QCPAxis* Vaxis = senderCanvas->axisRect()->rangeDragAxis(Qt::Vertical);
  double diff = 0;

  if (isMouseHold_)
  {
    if (senderCanvas->xAxis->scaleType() == QCPAxis::stLinear)
    {
      diff = Haxis->pixelToCoord(mDragStart_.x()) - Haxis->pixelToCoord(event->pos().x());
      Haxis->setRange(DragStartHorzRange_.lower + diff, DragStartHorzRange_.upper - diff);
    }
    if (senderCanvas->yAxis->scaleType() == QCPAxis::stLinear)
    {
      diff = Vaxis->pixelToCoord(mDragStart_.y()) - Vaxis->pixelToCoord(event->pos().y());
      Vaxis->setRange(DragStartVertRange_.lower + diff, DragStartVertRange_.upper - diff);
    }
    senderCanvas->replot();
  }
}

/* Ообрабатываем нажатие кнопок мыши */
void MainWindow::slotMousePress(QMouseEvent* event)
{
  QCustomPlot* senderCanvas = qobject_cast<QCustomPlot*>(sender());
  if (!senderCanvas)
    return;

  if (event->button() == Qt::RightButton)
  {
    mouseHoldTimer_.start();
    setCursor(Qt::ClosedHandCursor);
    mDragStart_ = event->pos();
    isMouseHold_ = true;
    DragStartHorzRange_ = senderCanvas->axisRect()->rangeDragAxis(Qt::Horizontal)->range();
    DragStartVertRange_ = senderCanvas->axisRect()->rangeDragAxis(Qt::Vertical)->range();
  }
}

/* Обрабатываем отпускание кнопок мыши */
void MainWindow::slotMouseRelease(QMouseEvent* event)
{
  QCustomPlot* senderCanvas = qobject_cast<QCustomPlot*>(sender());
  if (!senderCanvas)
    return;

  if (event->button() == Qt::RightButton)
  {
    setCursor(Qt::ArrowCursor);
    isMouseHold_ = false;

    // Проверяем, сколько времени была зажата правая кнопка мыши
    if (mouseHoldTimer_.elapsed() >= 250)
    {
      // Если кнопка была зажата более 100 мс, то не показываем контекстное меню
      return;
    }
    else
    {
      activeCanvas = senderCanvas;
      // Иначе показываем контекстное меню
      QMenu* menu = new QMenu(this);
      menu->addAction(tr("Сохранить изображение"), this, SLOT(slotSavePlotPNG()));
      menu->addAction(tr("Сохранить данные в .txt"), this, SLOT(slotSaveDataFromPlot()));
      menu->addAction(tr("Восстановить размер"), this, SLOT(slotResetCanvas()));

      QPoint pos = event->globalPos();
      pos.rx() += 10;
      pos.ry() -= 75;
      menu->exec(pos); // Исправлено для показа меню

      delete menu;
    }
  }
}

/* Обрабатываем двойной щелчок мыши */
void MainWindow::slotMouseDoubleClick(QMouseEvent* event)
{
  if (event->button() == Qt::LeftButton)
  {
    // Здесь можно добавить логику, если требуется реакция на двойной щелчок
  }
}
