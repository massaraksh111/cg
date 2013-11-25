#include "stdafx.h"
#include "Form1.h"

namespace project
{
	Drawing::Graphics^ Form1::canvas() { return pictureBox1->CreateGraphics();}

	// очищает холст
	void Form1::clearCanvas()
	{
		canvas()->Clear(Color::White);
	}

	// рисует линию
	void Form1::drawLine(int x1, int y1, int x2, int y2)
	{
		int x = x1, y = y1, dx = Math::Abs(x1-x2),
			dy = Math::Abs(y1-y2), s1 = Math::Sign(x2-x1),
			s2 = Math::Sign(y2-y1);

		int e;
		bool swapped = false;

		if(dy > dx)
		{
			std::swap(dx, dy);
			swapped = true;
		}

		e = 2*dy - dx;

		for(int i = 0; i <= dx; i++)
		{
			drawPoint(x, y);

			while(e >= 0)
			{
				if(swapped)
					x += s1;
				else
					y += s2;

				e = e - 2*dx;
			}

			if(swapped)
				y += s2;
			else
				x += s1;

			e = e + 2*dy;
		}

	}

	// рисует точку
	void Form1::drawPoint(int x, int y)
	{
		canvas()->FillRectangle(brush, x, y, 1, 1);
	}

	// рисует много линий
	void Form1::drawLines()
	{
		clearCanvas();

		auto c = canvas();

		int width = pictureBox1->Width;
		int height = pictureBox1->Height;

		int shiftX = width / 20;
		int shiftY = height / 20;
		int eps = 2;

		drawLine(shiftX, shiftY, width - shiftX, height - shiftY);
		c->DrawLine(circlePen, shiftX+eps, shiftY+eps, width - shiftX+eps, height - shiftY+eps);

		drawLine(width / 2, shiftY, width / 2, height - shiftY);
		c->DrawLine(circlePen, width / 2+eps, shiftY+eps, width / 2+eps, height - shiftY+eps);

		drawLine(shiftX, height / 2, width - shiftX, height / 2);
		c->DrawLine(circlePen, shiftX+eps, height / 2+eps, width - shiftX+eps, height / 2+eps);

		drawLine(shiftX, height - shiftY, width - shiftX, shiftY);
		c->DrawLine(circlePen, shiftX+eps, height - shiftY+eps, width - shiftX+eps, shiftY+eps);

	}

	// рисует круг
	void Form1::drawCircle(int R, int shiftX, int shiftY)
	{
		int x = 0, y = R, d = 2*(1-R), lim = 0;

		int eps = 2;

		canvas()->DrawEllipse(circlePen, shiftX - R - eps, shiftY - R - eps, 2*R, 2*R);

		while(true)
		{
			drawPoint(shiftX + x, shiftY + y);
			drawPoint(shiftX + x, shiftY - y);
			drawPoint(shiftX - x, shiftY + y);
			drawPoint(shiftX - x, shiftY - y);

			int flag = 0;

			if(y <= lim)
				return;
			else
			{
				flag = 0;
				int temp = 0;

				if(d < 0)
				{
					temp = 2*d + 2*y - 1;
					if(temp <= 0)
						flag = 2;
					else
						flag = 1;
				}
				else
				{
					if(d > 0)
					{
						temp = 2*d - 2*x - 1;

						if(temp <= 0)
							flag = 1;
						else
							flag = 0;
					}
					else
					{
						flag = 1;
					}
				}
			}

			switch(flag)
			{
			case 0:
				y--;
				d = d - 2*y + 1;
				;break;

			case 1:
				y--;
				x++;
				d = d - 2*y + 2 + 2*x;
				;break;


			case 2:
				x++;
				d = d + 2*x + 1;
				;break;
			}
		}
	}

	// заполняет прямоугольник кроме круга в нём
	void Form1::fill1()
	{
		Bitmap^ bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);


		int x1 = pictureBox1->Width * 0.15 - 10,
			x2 = pictureBox1->Width * 0.92 + 10;

		int y1 = pictureBox1->Height * 0.2 + 15,
			y2 = pictureBox1->Height * 0.75 + 40;

		Graphics^ bitmap = Graphics::FromImage(bm);

		bitmap->Clear(Color::White);

		bitmap->DrawLine(linePen, x1, y1, x2, y1);
		bitmap->DrawLine(linePen, x2, y1, x2, y2);
		bitmap->DrawLine(linePen, x1, y1, x1, y2);
		bitmap->DrawLine(linePen, x1, y2, x2, y2);

		Color ground = Color::Red;

		int X = bm->Width,
			Y = bm->Height;

		int r1 = std::min(x1, y1);


		int centerX = x1 + r1;
		int centerY = y1 + r1;

		int size = 0;
		for(int y = 0; y < y2; y++)
		{
			bool trigger = false;
			for(int x = 0; x < x2; x++)
			{
				Color col = bm->GetPixel(x, y);
				if(col.ToArgb() == lineColor.ToArgb())
				{
					trigger = !trigger;
				}

				if(trigger && ( (x - centerX)*(x - centerX) + (y - centerY)*(y - centerY) >= r1*r1 ))
					bm->SetPixel(x, y, ground);
			}
		}

		canvas()->DrawImage(bm, 0, 0);
	}

	void Form1::linesClicked(System::Object^, System::EventArgs^)
	{
		drawLines();
	}

	void Form1::clearAll(System::Object^, System::EventArgs^)
	{
		clearCanvas();
	}

	void Form1::circleClicked(System::Object^, System::EventArgs^)
	{
		clearCanvas();


		int R = (std::min(pictureBox1->Width, pictureBox1->Height) / 2) * 0.95;

		int shiftX = pictureBox1->Width / 2,
			shiftY = pictureBox1->Height / 2;

		drawCircle(R, shiftX, shiftY);
	}

	void Form1::Fill1(System::Object^, System::EventArgs^)
	{
		clearCanvas();

		fill1();
	}

	void Form1::Fill2(System::Object^, System::EventArgs^)
	{
		clearCanvas();

		int x1 = pictureBox1->Width * 0.15,
			x2 = pictureBox1->Width * 0.8;

		int y1 = pictureBox1->Height * 0.2,
			y2 = pictureBox1->Height * 0.75;

		canvas()->FillRectangle(brush, x1, y1, pictureBox1->Width * 0.65, pictureBox1->Height * 0.55);
		canvas()->FillEllipse(gcnew SolidBrush(Color::White), x1, y1, 50, 50);
	}
}