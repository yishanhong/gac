﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::VScrollTemplate

This file is generated by: Vczh GacUI Resource Code Generator
***********************************************************************/

#include <math.h>
#include "HelloWorld.h"

namespace demos
{
	// #region CLASS_MEMBER_GUIEVENT_HANDLER (DO NOT PUT OTHER CONTENT IN THIS #region.)

	void VScrollTemplate::OnHandleMouseDown(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments)
	{
		if (sender->GetRelatedControl()->GetVisuallyEnabled())
		{
			draggingHandle = true;
			draggingStartLocation = Point(arguments.x, arguments.y);
		}
	}

	void VScrollTemplate::OnHandleMouseMove(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments)
	{
		draggingHandle = false;
	}

	void VScrollTemplate::OnHandleMouseUp(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments)
	{
		if (draggingHandle)
		{
			vint totalPixels = handle->GetParent()->GetBounds().Height();
			vint currentOffset = handle->GetBounds().Top();
			vint newOffset = currentOffset + (arguments.y - draggingStartLocation.y);
			vint totalSize = GetTotalSize();
			double ratio = (double)newOffset / totalPixels;
			vint newPosition = (vint)(ratio * totalSize);

			vint offset1 = (vint)(((double)newPosition / totalSize) * totalPixels);
			vint offset2 = vint(((double)(newPosition + 1) / totalSize) * totalPixels);
			vint delta1 = abs((int)(offset1 - newOffset));
			vint delta2 = abs((int)(offset2 - newOffset));

			if(delta1 < delta2)
			{
				GetCommands()->SetPosition(newPosition);
			}
			else
			{
				GetCommands()->SetPosition(newPosition + 1);
			}
		}
	}

	// #endregion CLASS_MEMBER_GUIEVENT_HANDLER

	VScrollTemplate::VScrollTemplate()
	{
		InitializeComponents();
	}
}
