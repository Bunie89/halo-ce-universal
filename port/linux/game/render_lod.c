/*
RENDER_LOD.C

The Video menu's DETAIL setting (display.detail, port_config.c): how far the
Xbox's model LODs and shadows reach. "classic" keeps them as they were,
"enhanced" holds high-detail models and shadows about twice as far, "ultra"
about four times as far, by scaling the on-screen size (pixels) the LOD
cutoffs (models.c's detail_cutoff_pixels) and the shadow cutoff
(render_objects.c's OBJECT_SHADOW_MINIMUM_PIXELS) compare against. Visual
only: lighting refresh and the simulation keep the unscaled size.
*/

#include "cseries.h"

#include <string.h>

/* the platform layer's (port/linux/src/port_config.c) */
const char *config_string(const char *name);

float render_lod_scale(void)
{
	const char *detail = config_string("display.detail");

	if (!strcmp(detail, "ultra"))
		return 4.0f;
	if (!strcmp(detail, "enhanced"))
		return 2.0f;
	return 1.0f;
}
