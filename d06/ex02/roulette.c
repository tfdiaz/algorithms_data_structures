/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 08:46:53 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 08:46:54 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame) {
    double pr = 0;
    if (firstDollarsBet == 0 || nbGame < 0)
        return 0;
    if (firstDollarsBet >= dollarsWanted)
        return 1;
    pr += probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) * ((double)18 / (double)37);
    pr += probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1) * ((double)1 / (double)37);
    return pr;
}
