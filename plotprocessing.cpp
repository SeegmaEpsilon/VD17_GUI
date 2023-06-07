#include <mainwindow.h>
#include <ui_mainwindow.h>

void MainWindow::plotGraph(QString &msg)
{
    uint8_t flag_select_value = 0;

    /* finding a double value in the string */
    foreach(QString numStr, msg.split(" ", QString::SkipEmptyParts))
    {
        if(numStr == "A(RMS)") flag_select_value = 1;
        if(numStr == "V(RMS)") flag_select_value = 2;

        bool check = false;
        numStr.toDouble(&check);
        if(check)
        {
            if(flag_select_value == 1)
            {
                flagMeasureDone = 1;
                valueA = numStr.toDouble();
            }
            if(flag_select_value == 2)
            {
                if(flagMeasureDone == 1) flagMeasureDone = 2;
                valueV = numStr.toDouble();
            }
        }
        else continue;
    }

    if(flagMeasureDone == 2)
    {
        flagMeasureDone = 0;

        cbA.push(valueA);
        cbV.push(valueV);

        ui->lineEdit_RMS_A->setText(QString::number(valueA, 'f', 2));
        ui->lineEdit_RMS_V->setText(QString::number(valueV, 'f', 2));

        ui->lineEdit_average_A->setText(QString::number(cbA.average(), 'f', 2));
        ui->lineEdit_average_V->setText(QString::number(cbV.average(), 'f', 2));

        if(ui->checkBox_need_plot->isChecked() == false) return;
        counter++;

        if(ui->canvas->graphCount() < 2)
        {
          ui->canvas->addGraph();
          ui->canvas->addGraph();
        }

        ui->canvas->legend->setVisible(true);
        QFont legendFont = font();
        legendFont.setPointSize(8);
        ui->canvas->legend->setFont(legendFont);
        ui->canvas->legend->setBrush(QBrush(QColor(255,255,255,230)));

        ui->canvas->graph(0)->setName("Виброускорение (СКЗ)");
        ui->canvas->graph(0)->setPen(QPen(Qt::blue));
        ui->canvas->graph(0)->addData(counter, valueA);
        ui->canvas->graph(0)->rescaleAxes(true);

        ui->canvas->graph(1)->setName("Виброскорость (СКЗ)");
        ui->canvas->graph(1)->setPen(QPen(Qt::red));
        ui->canvas->graph(1)->addData(counter, valueV);
        ui->canvas->graph(1)->rescaleAxes(true);

        ui->canvas->replot();
    }
}

void MainWindow::slotResetCanvas(void)
{
  ui->canvas->rescaleAxes();
  ui->canvas->replot();
}

void MainWindow::slotSavePlotPNG()
{
  QString file_name = QFileDialog::getSaveFileName(this,
                                                   tr("Сохранить изображение"),
                                                   QCoreApplication::applicationDirPath () + "/VD17",
                                                   tr("Изображение (*.png)"));
  ui->canvas->savePng(file_name);
}

void MainWindow::slotSaveDataFromPlot(void)
{
  QString file_name = QFileDialog::getSaveFileName(this,
                                                   tr("Сохранить данные"),
                                                   QCoreApplication::applicationDirPath () + "/VD17",
                                                   tr("Данные (*.txt)"));

  const QCPGraph *graph1 = qobject_cast<const QCPGraph*>(ui->canvas->graph(0));
  const QCPGraph *graph2 = qobject_cast<const QCPGraph*>(ui->canvas->graph(1));

  QFile file(file_name);
  if(file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    QTextStream writeStream(&file);

    if(graph1 && graph2)
    {
      const QCPDataMap *plotData1 = graph1->data();
      const QCPDataMap *plotData2 = graph2->data();
      QCPDataMap::const_iterator it1 = plotData1->constBegin();
      QCPDataMap::const_iterator it2 = plotData2->constBegin();

      while(it1 != plotData1->constEnd() && it2 != plotData2->constEnd())
      {
        double y1 = it1.value().value;
        double y2 = it2.value().value;
        writeStream << QString("%1,%2\n").arg(QString::number(y1, 'f', 2)).arg(QString::number(y2, 'f', 2));

        ++it1;
        ++it2;
      }
    }
    file.close();
  }
  else return;
}
