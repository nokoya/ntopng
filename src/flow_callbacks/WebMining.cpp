/*
 *
 * (C) 2013-21 - ntop.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#include "ntop_includes.h"
#include "flow_callbacks_includes.h"

void WebMining::protocolDetected(Flow *f) {
  if (f->get_protocol_category() == CUSTOM_CATEGORY_MINING) {
    u_int8_t c_score = 50, s_score = 10;
   
    f->triggerAlertAsync(WebMiningAlert::getClassType(), getSeverity(), c_score, s_score);
  }
}

/* ***************************************************** */

FlowAlert *WebMining::buildAlert(Flow *f) {
  return new WebMiningAlert(this, f);
}

/* ***************************************************** */